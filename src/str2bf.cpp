#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

static const int max_pool_size = 20;

using namespace std;

//#define VERBOSE_DEBUG 1

string bf_add_value_simple(int x)
{
	string ret;
	for(;x>0;x--)
	{
		ret+='+';
	}
	for(;x<0;x++)
	{
		ret+='-';
	}
	return ret;
}

string bf_add_value(int x)
{
	int factor(16);

	string ret;

	int i;

	if(abs(x)>factor)factor/=2;
	if(abs(x)==factor)factor++;
	if(abs(x)==15)factor=5;
	if(abs(x)==16)factor=4;

	for(i=(x%factor);i>0;i--) ret+='+';
	for(i=(x%factor);i<0;i++) ret+='-';

	i=(x/factor);
	if(i)
	{
		ret+='>';
		ret+=bf_add_value(abs(i));
		ret+="[<";
		if(i>0)for(i=0;i<factor;i++) ret+='+';
		else for(i=0;i<factor;i++) ret+='-';
		ret+=">-]<";
	}
	return ret;
}

string bf_move_ptr(int x)
{
	string ret;
	for(;x>0;x--) ret+='>';
	for(;x<0;x++) ret+='<';
	return ret;
}

string str2bf2(const string& str)
{
	string ret;
	int cur_val(0);

	string::const_iterator iter;
	for(iter=str.begin();iter!=str.end();++iter)
	{
		string option1(bf_add_value(*iter-cur_val));
		string option2("[-]"+bf_add_value(*iter));
		ret+=option1.size()<option2.size()?option1:option2;
		cur_val=*iter;
		ret+='.';
	}
	return ret;
}

int find_optimal_mult(const char* pool, int poolsize)
{
	int mult=10;
#if 0
// OLD VERSION
	{
		int oldval(100000000);

		for(int i=mult;i<24;i++)
		{
			int newval(0);
			for (int j = 0; j < poolsize; j++) {
				newval += (pool[j] % i) + j
                    ? 0
                    : 1;
            }

			if (newval < oldval) {
                mult = i;
                oldval = newval;
            }
		}
	}
	return mult;
#elif 0
// NEW VERISON
	{
		int oldval(100000000);

		for(int i=mult;i<24;i++)
		{
			int newval(0);
			for (int j = 0; j < poolsize; j++) {
				newval += (pool[j] % i)
                    ? 0
                    : 1;
            }

			if (newval < oldval) {
                mult = i;
                oldval = newval;
            }
		}
	}
#endif
#if VERBOSE_DEBUG
//    fprintf(stderr,"mult=%d\n",mult);
#endif
	return mult;
}

int pool_decimate(int value, int mult)
{
    return (value+mult/2)/mult;
}

void pool_round(char* pool, int poolsize, int mult)
{
	for(int i=0;i<poolsize;i++)
	{
		pool[i]=pool_decimate(pool[i],mult);
		pool[i]*=mult;
	}
}

string bf_print_pool(const char* pool, int poolsize, int mult)
{
    string ret;

	// Output the pool
	ret+=bf_add_value(mult)+"[-";
	for(int i=0;i<poolsize;i++)
	{
		ret += bf_move_ptr(1);
		ret += bf_add_value(pool_decimate(pool[i],mult));
	}
	ret+=bf_move_ptr(-poolsize)+"]";
	ret+=bf_move_ptr(1);

    return ret;
}

int calc_pool_print_size(const char* pool, int poolsize)
{
#if 1
	int mult(find_optimal_mult(pool,poolsize));
    return bf_print_pool(pool, poolsize, mult).size();
#else
    int ret = 0;
	int mult(find_optimal_mult(pool,poolsize));

	ret += (bf_add_value(mult).size()+2);
	for(int i=0;i<poolsize;i++)
	{
		ret+=bf_move_ptr(1).size();
		ret+=bf_add_value((pool[i]+mult/2)/mult).size();
	}
	ret+=bf_move_ptr(-poolsize).size()+1;
	ret+=bf_move_ptr(1).size();

    return ret;
#endif
}

void calculate_pool2(char* pool, int &poolsize, const string& str)
{
	int cur_pos = 0;
    int cur_pool_size = 0;
	char temppool[20];
	string::const_iterator iter;
    int excess = 0;

    poolsize = 1;


    // First value in pool is the first character of the pool.
    temppool[0] = pool[0] = str[0];

    cur_pool_size = calc_pool_print_size(pool, poolsize);

	for(iter=str.begin();iter!=str.end();++iter)
	{
		int newpos = cur_pos;

		// Find closest value
		for(int i=0;i < poolsize; i++) {
			if(abs(temppool[i]-*iter)+abs(i-cur_pos)/2 <abs(temppool[newpos]-*iter)) {
                newpos = i;
            }
        }

        if (poolsize < max_pool_size) {
            static const int weird_factor = 4;
            const int blah_factor = 30 - poolsize;
            temppool[poolsize] = pool[poolsize] = *iter;
            int new_pool_size = calc_pool_print_size(pool, poolsize+1);
            int cost = abs(pool[newpos]-*iter)+abs(newpos-cur_pos);
            int pool_size_diff = (new_pool_size-cur_pool_size);

            pool_size_diff += abs(poolsize-cur_pos) + weird_factor - excess;

#if VERBOSE_DEBUG
            fprintf(stderr,"'%c': cost = %d; pool_size_diff = %d\n",*iter,cost, pool_size_diff);
#endif
            if (cost > pool_size_diff ) {
#if VERBOSE_DEBUG
                fprintf(stderr," >>> New slot\n");
#endif
                newpos = poolsize++;
                excess = 0;
                cur_pool_size = new_pool_size;
            } else if (cost > blah_factor) {
                excess += cost - blah_factor;
            }

            cur_pos=newpos;
        }

		temppool[cur_pos]+=*iter-temppool[cur_pos];
	}

#if VERBOSE_DEBUG
    fprintf(stderr," <<< Pool Size = %d\n", poolsize);
#endif
}

// This is the old broken pool calculator
void calculate_pool(char* pool, int &poolsize, const string& str)
{
	{
		// Find pool values
		string tmp(str);
		sort(tmp.begin(),tmp.end());

		if(str.size()>=poolsize) {
			for(int i=0;i<str.size();i++)
				pool[i]=str[i];
			return;
		}
		int range(tmp[tmp.size()-1]-tmp[0]);
		int std_dev(tmp[(tmp.size()-1)*2/3]-tmp[(tmp.size()-1)/3]);
		int threshold((8*range/(std_dev?std_dev:1))*1/((poolsize>3)?poolsize-3:1));

		//fprintf(stderr,"range=%d\n",range);
		//fprintf(stderr,"std_dev=%d\n",std_dev);
		//fprintf(stderr,"threshold=%d\n",threshold);
		
		vector<int> loc;
		/*
		vector< pair<int, int> > cost;

		for(int i=0;i<tmp.size();i++)
		{
			int my_value(tmp[i]);
			cost.push_back(pair<int, int>(0,0));
			cost.back().second=my_value;
			for(int j=0;j<tmp.size();j++)
			{
				cost[i].first+=100/(abs(my_value-tmp[j]));
			}
			fprintf(stderr,"%c:%d,",tmp[i],cost[i].first);
		}
		fprintf(stderr,"\n");

		sort(cost.begin(),cost.end());
		*/
		
		for(int i=0;i<poolsize;i++)
		{
			loc.push_back(i*(tmp.size()-1)/(poolsize-1));
			pool[i]=tmp[loc.back()];
			pool[i]=(tmp[tmp.size()-1]-tmp[0])*i/(poolsize-1)+tmp[0];
		}

		/*
		for(int i=poolsize-1;i>0;i--)
		{
			if(pool[i-1]>pool[i])
			{
				pool[i-1]=pool[i];
				loc[i-1]=loc[i];				
			}
			while(pool[i]-pool[i-1]<threshold && loc[i-1]>0)
			{
				loc[i-1]--;
				pool[i-1]=tmp[loc[i-1]];
			}
		}
		*/
	}

	// Find closest value to the first letter
#if 1
	{
		int newpos=0;
		for(int i=0;i<poolsize;i++)
			if(abs(pool[i]-str[0])<abs(pool[newpos]-str[0])) newpos=i;
		swap(pool[0],pool[newpos]);
		pool[0]=str[0];
	}
#endif
}

string str2bf(const string& str)
{
	string ret;

	char pool[20] = { 0x0a, 0x1e, 0x46, 0x64 };
	
	int poolsize(12);
	
	int cur_pos=0;
//	if(str.size()<2) {
//		return str2bf2(str);
//	} else
//	if(str.size()<5)
//		poolsize=2;
//	else
//	if(str.size()<10)
//		poolsize=3;
//	else
//	if(str.size()<25)
//		poolsize=4;
//	else
//	if(str.size()<35)
//		poolsize=4;
//	else
//	if(str.size()<40)
//		poolsize=5;
//	else
//		poolsize=5;
//
//	poolsize=std::min(2+int(sqrt((float)str.size()*2.0+80))/(415/70),12);
//
//	calculate_pool(pool,poolsize,str);
	calculate_pool2(pool,poolsize,str);


	int mult(find_optimal_mult(pool,poolsize));

    pool_round(pool, poolsize, mult);
    ret += bf_print_pool(pool, poolsize, mult);


	string::const_iterator iter;
	for(iter=str.begin();iter!=str.end();++iter)
	{
		int newpos=cur_pos;

		// Find closest value
		for(int i=0;i<poolsize;i++)
			if(abs(pool[i]-*iter)+abs(i-cur_pos)/2 <abs(pool[newpos]-*iter)) newpos=i;

		ret+=bf_move_ptr(newpos-cur_pos);
		cur_pos=newpos;
		ret+=bf_add_value_simple(*iter-pool[cur_pos])+'.';
		pool[cur_pos]+=*iter-pool[cur_pos];
	}

	string ret2(str2bf2(str));
	return ret.size()<ret2.size()?ret:ret2;
}

string optimize(string code)
{
	string opt;
	string::iterator iter,next;
	int i=0;
	int changes=0;
	do{
	changes=0;
	for(iter=code.begin();iter!=code.end();++iter)
	{
		if(opt.size())
		{
			if(opt.end()[-1]=='>' && *iter=='<')
			{
				opt=string(opt.begin(),opt.end()-1);
				changes++;
				continue;
			}
			if(opt.end()[-1]=='<' && *iter=='>')
			{
				opt=string(opt.begin(),opt.end()-1);
				changes++;
				continue;
			}
		}
		opt+=*iter;
	}
	code=opt;
	opt=std::string();
	} while(changes);
	return code;
}

int main(int argc, char *argv[])
{
	int line_width(70);
	int lines(0);
	int cur_col(0);
	string code("[-]");

	if(argc>1)
	{
		code=std::string();
		for(int i=1;i<argc;i++)
		{ code+=argv[i]; if(i!=argc-1)code+=' '; }
		code=optimize(str2bf(code));
		string::iterator iter;
		for(iter=code.begin();iter!=code.end();++iter)
		{
			if(cur_col>line_width)cout<<endl,cur_col=0,lines++;
			cur_col++;
			cout<<*iter;
		}
	}
	else while (!cin.eof())
	{
		if(code[code.size()-1]!=']')
			code="[>]";
		else
			code=std::string();
		string line;
		do { char tmp(cin.get()); if(!cin.eof())line+=tmp; } while(!cin.eof() && line[line.size()-1]!='\n');
		//getline(cin,line);
		//line+='\n';
		code+=optimize(str2bf(line));
		string::iterator iter;
		for(iter=code.begin();iter!=code.end();++iter)
		{
			if(cur_col>line_width)cout<<endl,cur_col=0,lines++;
			cur_col++;
			cout<<*iter;
		}
	}
	cout<<endl;
	return 0;
}

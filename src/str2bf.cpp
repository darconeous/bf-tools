#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

void calculate_pool(char* pool, int poolsize, const string& str)
{
	{
		// Find pool values
		string tmp(str);
		sort(tmp.begin(),tmp.end());

		int range(tmp[tmp.size()-1]-tmp[0]);
		int std_dev(tmp[(tmp.size()-1)*2/3]-tmp[(tmp.size()-1)/3]);
		int threshold((8*range/std_dev)*1/(poolsize-3));

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

int find_optimal_mult(char* pool, int poolsize)
{
	int mult=16;
	{
		int oldval(100000000);
		
		for(int i=10;i<24;i++)
		{
			int newval(0);
			for(int j=0;j<poolsize;j++)
				newval+=pool[j]%i+j?0:1;
				
			if(newval<oldval) mult=i,oldval=newval;
		}
	}
	return mult;
}

string str2bf(const string& str)
{
	string ret;

	char pool[20] = { 0x0a, 0x1e, 0x46, 0x64 };
	
	int poolsize(12);
	
	int cur_pos=0;
	if(str.size()<5)
		poolsize=2;
	else
	if(str.size()<10)
		poolsize=3;
	else
	if(str.size()<25)
		poolsize=4;
	else
	if(str.size()<35)
		poolsize=4;
	else
	if(str.size()<40)
		poolsize=5;
	else
		poolsize=5;
		
	//poolsize=std::min(2+int(sqrt((float)str.size()*2.0+80))/(415/70),12);
	
	calculate_pool(pool,poolsize,str);
	
	int mult(find_optimal_mult(pool,poolsize));

	// Output the pool
	ret+=bf_add_value(mult)+"[-";
	for(int i=0;i<poolsize;i++)
	{
		ret+=bf_move_ptr(1);
		pool[i]=(pool[i]+mult/2)/mult;
		ret+=bf_add_value(pool[i]);
		pool[i]*=mult;
	}
	ret+=bf_move_ptr(-poolsize)+"]";
	ret+=bf_move_ptr(1);

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

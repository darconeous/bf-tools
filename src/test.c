#include <stdio.h>
int main(void) {int data[65536]={0};int* dp=data;
dp[0]+=13;
dp[1]+=*dp * 2;
dp[4]+=*dp * 5;
dp[5]+=*dp * 2;
dp[6]+=*dp * 1;
dp[0]=0;
dp+=5;
dp[0]+=6;
dp++;
dp[0]+=-3;
dp+=10;
dp[0]+=15;
if(!*dp) goto pc0018;
pc0012:
while(*dp)dp+=9;
dp[0]++;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc0012;
pc0018:
dp[0]++;
if(!*dp) goto pc0024;
pc0020:
dp+=8;
dp[0]=0;
dp++;
if(*dp) goto pc0020;
pc0024:
dp+=-9;
while(*dp)dp+=-9;
dp+=8;
dp[0]=0;
dp[0]++;
dp+=-7;
dp[0]+=5;
if(!*dp) goto pc0037;
pc0032:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc0032;
pc0037:
dp+=7;
dp[0]++;
dp+=27;
dp[0]++;
dp+=-17;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
if(!*dp) goto pc2666;
pc0047:
dp+=6;
if(!*dp) goto pc0053;
pc0049:
dp+=7;
dp[0]=0;
dp+=2;
if(*dp) goto pc0049;
pc0053:
dp+=-9;
while(*dp)dp+=-9;
dp+=7;
dp[0]=0;
dp[0]++;
dp+=-6;
dp[0]+=4;
if(!*dp) goto pc0066;
pc0061:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc0061;
pc0066:
dp+=6;
dp[0]++;
dp+=-6;
dp[0]+=7;
if(!*dp) goto pc0076;
pc0071:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc0071;
pc0076:
dp+=6;
dp[0]++;
dp+=-16;
while(*dp)dp+=-9;
dp+=3;
if(!*dp) goto pc2395;
pc0082:
dp[0]=0;
dp+=6;
if(!*dp) goto pc0095;
pc0085:
dp+=7;
dp[-6]+=*dp * 1;
dp[0]=0;
dp+=-6;
dp[1]+=*dp * 1;
dp[4]+=*dp * 1;
dp[6]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc0085;
pc0095:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0109;
pc0099:
dp+=8;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
dp[2]+=*dp * 1;
dp[5]+=*dp * 1;
dp[7]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc0099;
pc0109:
dp+=-9;
while(*dp)dp+=-9;
dp+=7;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
dp[5]+=*dp * 1;
dp[7]+=*dp * 1;
dp[0]=0;
dp+=9;
dp[0]+=15;
if(!*dp) goto pc0146;
pc0121:
while(*dp)dp+=9;
dp[0]++;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc0121;
pc0146:
dp[0]++;
if(!*dp) goto pc0152;
pc0148:
dp++;
dp[0]++;
dp+=8;
if(*dp) goto pc0148;
pc0152:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0198;
pc0156:
dp++;
dp[0]--;
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc0182;
pc0163:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-5;
if(!*dp) goto pc0179;
pc0168:
dp[0]--;
dp+=2;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=9;
if(*dp) goto pc0168;
pc0179:
dp+=-8;
while(*dp)dp+=-9;
if(*dp) goto pc0163;
pc0182:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc0191;
pc0186:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-10;
if(*dp) goto pc0186;
pc0191:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=8;
if(*dp) goto pc0156;
pc0198:
dp+=-9;
if(!*dp) goto pc0225;
pc0200:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=4;
if(!*dp) goto pc0218;
pc0206:
dp[0]--;
dp+=-4;
dp[0]++;
dp++;
dp[-6]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=4;
if(*dp) goto pc0206;
pc0218:
dp+=-3;
dp[3]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc0200;
pc0225:
dp+=9;
if(!*dp) goto pc0231;
pc0227:
dp++;
dp[0]++;
dp+=8;
if(*dp) goto pc0227;
pc0231:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0277;
pc0235:
dp++;
dp[0]--;
dp+=5;
dp[-5]+=*dp * 1;
dp[0]=0;
dp+=-5;
if(!*dp) goto pc0261;
pc0242:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-6;
if(!*dp) goto pc0258;
pc0247:
dp[0]--;
dp+=3;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
dp[3]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=9;
if(*dp) goto pc0247;
pc0258:
dp+=-8;
while(*dp)dp+=-9;
if(*dp) goto pc0242;
pc0261:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc0270;
pc0265:
dp+=2;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-11;
if(*dp) goto pc0265;
pc0270:
dp+=2;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-2;
dp[0]++;
dp+=8;
if(*dp) goto pc0235;
pc0277:
dp+=-9;
if(!*dp) goto pc0304;
pc0279:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=4;
if(!*dp) goto pc0297;
pc0285:
dp[0]--;
dp+=-4;
dp[0]++;
dp++;
dp[-6]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=4;
if(*dp) goto pc0285;
pc0297:
dp+=-3;
dp[3]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc0279;
pc0304:
dp+=9;
if(!*dp) goto pc0311;
pc0306:
dp+=4;
dp[-36]+=*dp * 1;
dp[0]=0;
dp+=5;
if(*dp) goto pc0306;
pc0311:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]+=15;
if(!*dp) goto pc0324;
pc0316:
while(*dp)dp+=9;
dp+=-9;
dp[0]--;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc0316;
pc0324:
dp[0]++;
dp+=21;
dp[0]++;
dp+=-3;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0401;
pc0331:
dp+=3;
dp[-3]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-3;
if(!*dp) goto pc0360;
pc0337:
dp[0]--;
dp+=3;
dp[0]--;
dp++;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc0359;
pc0345:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-13;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp++;
dp[0]++;
dp--;
if(*dp) goto pc0345;
pc0359:
if(*dp) goto pc0337;
pc0360:
dp[0]++;
dp+=4;
dp[-4]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-4;
if(!*dp) goto pc0391;
pc0367:
dp[0]--;
dp+=4;
dp[0]--;
dp--;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc0390;
pc0375:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-12;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
dp+=6;
while(*dp)dp+=9;
dp++;
dp[0]=0;
dp[0]++;
dp--;
if(*dp) goto pc0375;
pc0390:
if(*dp) goto pc0367;
pc0391:
dp[0]++;
dp++;
if(!*dp) goto pc0399;
pc0394:
dp[0]--;
dp--;
while(*dp)dp+=9;
dp+=-8;
if(*dp) goto pc0394;
pc0399:
dp+=8;
if(*dp) goto pc0331;
pc0401:
dp+=-9;
while(*dp)dp+=-9;
dp+=-7;
dp[1]+=*dp * 1;
dp[4]+=*dp * -1;
dp[0]=0;
dp+=9;
dp[0]+=26;
dp+=2;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc0421;
pc0414:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-2;
dp[0]=0;
dp+=-2;
if(*dp) goto pc0414;
pc0421:
dp+=2;
if(!*dp) goto pc2078;
pc0423:
dp+=-7;
dp[0]++;
dp--;
if(!*dp) goto pc0435;
pc0427:
dp[0]--;
dp--;
dp[0]++;
dp+=4;
dp[0]++;
dp+=-2;
dp[0]=0;
if(*dp) goto pc0427;
pc0435:
dp++;
if(!*dp) goto pc0444;
pc0437:
dp[0]--;
dp+=-2;
dp[1]+=*dp * 1;
dp[4]+=*dp * -1;
dp[0]=0;
dp+=3;
if(*dp) goto pc0437;
pc0444:
dp+=13;
if(!*dp) goto pc0454;
pc0446:
dp+=2;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=5;
if(*dp) goto pc0446;
pc0454:
dp+=-9;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp+=6;
if(!*dp) goto pc0469;
pc0460:
dp+=5;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
dp[1]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc0460;
pc0469:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0478;
pc0473:
dp+=2;
dp[-9]+=*dp * 1;
dp[0]=0;
dp+=7;
if(*dp) goto pc0473;
pc0478:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]+=15;
if(!*dp) goto pc0508;
pc0483:
while(*dp)dp+=9;
dp[0]++;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc0483;
pc0508:
dp[0]++;
if(!*dp) goto pc0514;
pc0510:
dp++;
dp[0]++;
dp+=8;
if(*dp) goto pc0510;
pc0514:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0560;
pc0518:
dp++;
dp[0]--;
dp+=5;
dp[-5]+=*dp * 1;
dp[0]=0;
dp+=-5;
if(!*dp) goto pc0544;
pc0525:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-6;
if(!*dp) goto pc0541;
pc0530:
dp[0]--;
dp+=2;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[3]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=9;
if(*dp) goto pc0530;
pc0541:
dp+=-8;
while(*dp)dp+=-9;
if(*dp) goto pc0525;
pc0544:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc0553;
pc0548:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-10;
if(*dp) goto pc0548;
pc0553:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=8;
if(*dp) goto pc0518;
pc0560:
dp+=-9;
if(!*dp) goto pc0587;
pc0562:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=3;
if(!*dp) goto pc0580;
pc0568:
dp[0]--;
dp+=-3;
dp[0]++;
dp++;
dp[-7]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=3;
if(*dp) goto pc0568;
pc0580:
dp+=-2;
dp[2]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc0562;
pc0587:
dp+=9;
if(!*dp) goto pc0598;
pc0589:
dp+=6;
dp[-5]+=*dp * 1;
dp[0]=0;
dp+=-5;
dp[1]+=*dp * 1;
dp[5]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc0589;
pc0598:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0606;
pc0602:
dp++;
dp[0]++;
dp+=8;
if(*dp) goto pc0602;
pc0606:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0652;
pc0610:
dp++;
dp[0]--;
dp+=5;
dp[-5]+=*dp * 1;
dp[0]=0;
dp+=-5;
if(!*dp) goto pc0636;
pc0617:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-6;
if(!*dp) goto pc0633;
pc0622:
dp[0]--;
dp+=2;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=9;
if(*dp) goto pc0622;
pc0633:
dp+=-8;
while(*dp)dp+=-9;
if(*dp) goto pc0617;
pc0636:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc0645;
pc0640:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-10;
if(*dp) goto pc0640;
pc0645:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=8;
if(*dp) goto pc0610;
pc0652:
dp+=-9;
if(!*dp) goto pc0679;
pc0654:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=4;
if(!*dp) goto pc0672;
pc0660:
dp[0]--;
dp+=-4;
dp[0]++;
dp++;
dp[-6]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=4;
if(*dp) goto pc0660;
pc0672:
dp+=-3;
dp[3]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc0654;
pc0679:
dp+=9;
if(!*dp) goto pc0686;
pc0681:
dp+=4;
dp[-36]+=*dp * 1;
dp[0]=0;
dp+=5;
if(*dp) goto pc0681;
pc0686:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0695;
pc0690:
dp+=3;
dp[-36]+=*dp * 1;
dp[0]=0;
dp+=6;
if(*dp) goto pc0690;
pc0695:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]+=15;
if(!*dp) goto pc0708;
pc0700:
while(*dp)dp+=9;
dp+=-9;
dp[0]--;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc0700;
pc0708:
dp[0]++;
if(!*dp) goto pc0719;
pc0710:
dp+=8;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
dp[1]+=*dp * 1;
dp[7]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc0710;
pc0719:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc0727;
pc0723:
dp+=6;
dp[0]=0;
dp+=3;
if(*dp) goto pc0723;
pc0727:
dp+=-9;
while(*dp)dp+=-9;
dp+=4;
dp[0]++;
dp++;
dp[-5]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp++;
if(!*dp) goto pc0751;
pc0737:
dp[0]--;
dp+=-6;
dp[4]+=*dp * 2;
dp[5]+=*dp * 1;
dp[0]=0;
dp+=5;
dp[-5]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]--;
dp++;
dp[0]++;
dp++;
if(*dp) goto pc0737;
pc0751:
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=-5;
dp[5]+=*dp * 1;
dp[0]=0;
dp+=6;
dp[0]=0;
dp+=-6;
dp[0]++;
dp+=4;
dp[-4]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-4;
if(!*dp) goto pc0979;
pc0767:
dp[0]--;
dp+=4;
dp[0]--;
dp+=5;
if(!*dp) goto pc0842;
pc0772:
dp+=2;
dp[-2]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-2;
if(!*dp) goto pc0801;
pc0778:
dp[0]--;
dp+=2;
dp[0]--;
dp++;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc0800;
pc0786:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-12;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
dp+=6;
while(*dp)dp+=9;
dp++;
dp[0]++;
dp--;
if(*dp) goto pc0786;
pc0800:
if(*dp) goto pc0778;
pc0801:
dp[0]++;
dp+=3;
dp[-3]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-3;
if(!*dp) goto pc0832;
pc0808:
dp[0]--;
dp+=3;
dp[0]--;
dp--;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-2;
if(!*dp) goto pc0831;
pc0816:
dp[0]--;
dp+=2;
dp[0]++;
dp+=-11;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp++;
dp[0]=0;
dp[0]++;
dp--;
if(*dp) goto pc0816;
pc0831:
if(*dp) goto pc0808;
pc0832:
dp[0]++;
dp++;
if(!*dp) goto pc0840;
pc0835:
dp[0]--;
dp--;
while(*dp)dp+=9;
dp+=-8;
if(*dp) goto pc0835;
pc0840:
dp+=8;
if(*dp) goto pc0772;
pc0842:
dp+=-9;
while(*dp)dp+=-9;
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc0911;
pc0849:
dp[0]--;
dp+=4;
dp[0]++;
dp+=5;
if(!*dp) goto pc0864;
pc0854:
dp++;
dp[0]++;
dp+=2;
dp[-2]+=*dp * -1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc0854;
pc0864:
dp+=-8;
dp[0]++;
dp--;
if(!*dp) goto pc0907;
pc0868:
dp++;
if(!*dp) goto pc0891;
pc0870:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-4;
if(!*dp) goto pc0885;
pc0875:
dp[0]--;
dp+=4;
dp[0]--;
dp+=-14;
dp[0]++;
dp+=11;
dp[3]+=*dp * 1;
dp[0]=0;
dp--;
if(*dp) goto pc0875;
pc0885:
dp++;
dp[-11]+=*dp * 1;
dp[3]+=*dp * -1;
dp[0]=0;
dp+=-2;
if(*dp) goto pc0870;
pc0891:
dp++;
if(!*dp) goto pc0902;
pc0893:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-3;
dp[-11]+=*dp * 1;
dp[3]+=*dp * -1;
dp[0]=0;
dp--;
if(*dp) goto pc0893;
pc0902:
dp++;
dp[3]+=*dp * 1;
dp[0]=0;
dp+=-12;
if(*dp) goto pc0868;
pc0907:
dp+=4;
dp[0]=0;
dp+=-4;
if(*dp) goto pc0849;
pc0911:
dp+=3;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc0978;
pc0916:
dp[0]--;
dp+=3;
dp[0]++;
dp+=6;
if(!*dp) goto pc0931;
pc0921:
dp++;
dp[0]++;
dp++;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc0921;
pc0931:
dp+=-8;
dp[0]++;
dp--;
if(!*dp) goto pc0974;
pc0935:
dp++;
if(!*dp) goto pc0958;
pc0937:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-3;
if(!*dp) goto pc0952;
pc0942:
dp[0]--;
dp+=3;
dp[0]--;
dp+=-14;
dp[0]++;
dp+=10;
dp[4]+=*dp * 1;
dp[0]=0;
dp++;
if(*dp) goto pc0942;
pc0952:
dp--;
dp[-10]+=*dp * 1;
dp[4]+=*dp * -1;
dp[0]=0;
dp--;
if(*dp) goto pc0937;
pc0958:
dp+=2;
if(!*dp) goto pc0969;
pc0960:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-4;
dp[-10]+=*dp * 1;
dp[4]+=*dp * -1;
dp[0]=0;
dp++;
if(*dp) goto pc0960;
pc0969:
dp--;
dp[4]+=*dp * 1;
dp[0]=0;
dp+=-11;
if(*dp) goto pc0935;
pc0974:
dp+=6;
dp[0]++;
dp+=-6;
if(*dp) goto pc0916;
pc0978:
if(*dp) goto pc0767;
pc0979:
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc1031;
pc0984:
dp[0]--;
dp+=4;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc1030;
pc0991:
dp++;
if(!*dp) goto pc1014;
pc0993:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-4;
if(!*dp) goto pc1008;
pc0998:
dp[0]--;
dp+=4;
dp[0]--;
dp+=-14;
dp[0]++;
dp+=11;
dp[3]+=*dp * 1;
dp[0]=0;
dp--;
if(*dp) goto pc0998;
pc1008:
dp++;
dp[-11]+=*dp * 1;
dp[3]+=*dp * -1;
dp[0]=0;
dp+=-2;
if(*dp) goto pc0993;
pc1014:
dp++;
if(!*dp) goto pc1025;
pc1016:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-3;
dp[-11]+=*dp * 1;
dp[3]+=*dp * -1;
dp[0]=0;
dp--;
if(*dp) goto pc1016;
pc1025:
dp++;
dp[3]+=*dp * 1;
dp[0]=0;
dp+=-12;
if(*dp) goto pc0991;
pc1030:
if(*dp) goto pc0984;
pc1031:
dp++;
dp[0]=0;
dp+=2;
dp[0]=0;
dp++;
dp[0]=0;
dp+=5;
if(!*dp) goto pc1045;
pc1039:
dp+=2;
dp[0]=0;
dp++;
dp[0]=0;
dp+=6;
if(*dp) goto pc1039;
pc1045:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc1058;
pc1049:
dp+=5;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
dp[1]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1049;
pc1058:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]+=15;
if(!*dp) goto pc1088;
pc1063:
while(*dp)dp+=9;
dp[0]++;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc1063;
pc1088:
dp[0]++;
if(!*dp) goto pc1094;
pc1090:
dp++;
dp[0]++;
dp+=8;
if(*dp) goto pc1090;
pc1094:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc1140;
pc1098:
dp++;
dp[0]--;
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc1124;
pc1105:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-5;
if(!*dp) goto pc1121;
pc1110:
dp[0]--;
dp+=2;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[3]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=9;
if(*dp) goto pc1110;
pc1121:
dp+=-8;
while(*dp)dp+=-9;
if(*dp) goto pc1105;
pc1124:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc1133;
pc1128:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-10;
if(*dp) goto pc1128;
pc1133:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=8;
if(*dp) goto pc1098;
pc1140:
dp+=-9;
if(!*dp) goto pc1167;
pc1142:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=3;
if(!*dp) goto pc1160;
pc1148:
dp[0]--;
dp+=-3;
dp[0]++;
dp++;
dp[-7]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=3;
if(*dp) goto pc1148;
pc1160:
dp+=-2;
dp[2]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc1142;
pc1167:
dp+=9;
if(!*dp) goto pc1174;
pc1169:
dp+=3;
dp[-36]+=*dp * 1;
dp[0]=0;
dp+=6;
if(*dp) goto pc1169;
pc1174:
dp+=-9;
while(*dp)dp+=-9;
dp+=5;
dp[0]=0;
dp+=4;
dp[0]+=15;
if(!*dp) goto pc1189;
pc1181:
while(*dp)dp+=9;
dp+=-9;
dp[0]--;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc1181;
pc1189:
dp[0]++;
if(!*dp) goto pc1261;
pc1191:
dp+=3;
dp[-3]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-3;
if(!*dp) goto pc1220;
pc1197:
dp[0]--;
dp+=3;
dp[0]--;
dp++;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc1219;
pc1205:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-13;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp++;
dp[0]++;
dp--;
if(*dp) goto pc1205;
pc1219:
if(*dp) goto pc1197;
pc1220:
dp[0]++;
dp+=4;
dp[-4]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-4;
if(!*dp) goto pc1251;
pc1227:
dp[0]--;
dp+=4;
dp[0]--;
dp--;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc1250;
pc1235:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-12;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
dp+=6;
while(*dp)dp+=9;
dp++;
dp[0]=0;
dp[0]++;
dp--;
if(*dp) goto pc1235;
pc1250:
if(*dp) goto pc1227;
pc1251:
dp[0]++;
dp++;
if(!*dp) goto pc1259;
pc1254:
dp[0]--;
dp--;
while(*dp)dp+=9;
dp+=-8;
if(*dp) goto pc1254;
pc1259:
dp+=8;
if(*dp) goto pc1191;
pc1261:
dp+=-9;
while(*dp)dp+=-9;
dp+=3;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc1327;
pc1268:
dp[0]--;
dp+=3;
dp[0]++;
dp+=6;
if(!*dp) goto pc1283;
pc1273:
dp++;
dp[0]++;
dp+=3;
dp[-3]+=*dp * -1;
dp[0]=0;
dp+=-3;
dp[3]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1273;
pc1283:
dp+=-8;
dp[0]++;
dp--;
if(!*dp) goto pc1326;
pc1287:
dp++;
if(!*dp) goto pc1310;
pc1289:
dp[0]--;
dp++;
dp[0]++;
dp++;
if(!*dp) goto pc1304;
pc1294:
dp[0]--;
dp--;
dp[0]--;
dp+=-10;
dp[0]++;
dp+=12;
dp[-2]+=*dp * 1;
dp[0]=0;
dp--;
if(*dp) goto pc1294;
pc1304:
dp++;
dp[-12]+=*dp * 1;
dp[-2]+=*dp * -1;
dp[0]=0;
dp+=-3;
if(*dp) goto pc1289;
pc1310:
dp+=2;
if(!*dp) goto pc1321;
pc1312:
dp[0]--;
dp--;
dp[0]++;
dp+=2;
dp[-12]+=*dp * 1;
dp[-2]+=*dp * -1;
dp[0]=0;
dp--;
if(*dp) goto pc1312;
pc1321:
dp++;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-13;
if(*dp) goto pc1287;
pc1326:
if(*dp) goto pc1268;
pc1327:
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc1394;
pc1332:
dp[0]--;
dp+=4;
dp[0]++;
dp+=5;
if(!*dp) goto pc1347;
pc1337:
dp++;
dp[0]++;
dp+=2;
dp[-2]+=*dp * -1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1337;
pc1347:
dp+=-8;
dp[0]++;
dp--;
if(!*dp) goto pc1390;
pc1351:
dp++;
if(!*dp) goto pc1374;
pc1353:
dp[0]--;
dp++;
dp[0]++;
dp+=2;
if(!*dp) goto pc1368;
pc1358:
dp[0]--;
dp+=-2;
dp[0]--;
dp+=-10;
dp[0]++;
dp+=11;
dp[-1]+=*dp * 1;
dp[0]=0;
dp++;
if(*dp) goto pc1358;
pc1368:
dp--;
dp[-11]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp+=-2;
if(*dp) goto pc1353;
pc1374:
dp+=3;
if(!*dp) goto pc1385;
pc1376:
dp[0]--;
dp+=-2;
dp[0]++;
dp++;
dp[-11]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp++;
if(*dp) goto pc1376;
pc1385:
dp--;
dp[-1]+=*dp * 1;
dp[0]=0;
dp+=-12;
if(*dp) goto pc1351;
pc1390:
dp+=5;
dp[0]++;
dp+=-5;
if(*dp) goto pc1332;
pc1394:
dp+=9;
if(!*dp) goto pc1404;
pc1396:
dp+=3;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=4;
if(*dp) goto pc1396;
pc1404:
dp+=-9;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp++;
dp[0]=0;
dp+=5;
if(!*dp) goto pc1421;
pc1412:
dp+=7;
dp[-6]+=*dp * 1;
dp[0]=0;
dp+=-6;
dp[2]+=*dp * 1;
dp[6]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1412;
pc1421:
dp+=-9;
while(*dp)dp+=-9;
dp+=4;
dp[0]++;
dp++;
dp[-5]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp+=2;
if(!*dp) goto pc1445;
pc1431:
dp[0]--;
dp+=-7;
dp[4]+=*dp * 2;
dp[5]+=*dp * 1;
dp[0]=0;
dp+=5;
dp[-5]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]--;
dp++;
dp[0]++;
dp+=2;
if(*dp) goto pc1431;
pc1445:
dp+=-2;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=-5;
dp[5]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=4;
dp[-4]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-4;
if(!*dp) goto pc1676;
pc1458:
dp[0]--;
dp+=4;
dp[0]--;
dp+=5;
if(!*dp) goto pc1533;
pc1463:
dp+=3;
dp[-3]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-3;
if(!*dp) goto pc1492;
pc1469:
dp[0]--;
dp+=3;
dp[0]--;
dp--;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-2;
if(!*dp) goto pc1491;
pc1477:
dp[0]--;
dp+=2;
dp[0]++;
dp+=-11;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp++;
dp[0]++;
dp--;
if(*dp) goto pc1477;
pc1491:
if(*dp) goto pc1469;
pc1492:
dp[0]++;
dp+=2;
dp[-2]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-2;
if(!*dp) goto pc1523;
pc1499:
dp[0]--;
dp+=2;
dp[0]--;
dp++;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc1522;
pc1507:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-12;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
dp+=6;
while(*dp)dp+=9;
dp++;
dp[0]=0;
dp[0]++;
dp--;
if(*dp) goto pc1507;
pc1522:
if(*dp) goto pc1499;
pc1523:
dp[0]++;
dp++;
if(!*dp) goto pc1531;
pc1526:
dp[0]--;
dp--;
while(*dp)dp+=9;
dp+=-8;
if(*dp) goto pc1526;
pc1531:
dp+=8;
if(*dp) goto pc1463;
pc1533:
dp+=-9;
while(*dp)dp+=-9;
dp+=3;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc1608;
pc1540:
dp[0]--;
dp+=3;
dp[0]++;
dp+=6;
if(!*dp) goto pc1555;
pc1545:
dp++;
dp[0]++;
dp++;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1545;
pc1555:
dp+=-8;
dp[0]++;
dp--;
if(!*dp) goto pc1598;
pc1559:
dp++;
if(!*dp) goto pc1582;
pc1561:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-2;
if(!*dp) goto pc1576;
pc1566:
dp[0]--;
dp+=2;
dp[0]--;
dp+=-13;
dp[0]++;
dp+=10;
dp[3]+=*dp * 1;
dp[0]=0;
dp++;
if(*dp) goto pc1566;
pc1576:
dp--;
dp[-10]+=*dp * 1;
dp[3]+=*dp * -1;
dp[0]=0;
dp--;
if(*dp) goto pc1561;
pc1582:
dp+=2;
if(!*dp) goto pc1593;
pc1584:
dp[0]--;
dp+=2;
dp[0]++;
dp+=-3;
dp[-10]+=*dp * 1;
dp[3]+=*dp * -1;
dp[0]=0;
dp++;
if(*dp) goto pc1584;
pc1593:
dp--;
dp[3]+=*dp * 1;
dp[0]=0;
dp+=-11;
if(*dp) goto pc1559;
pc1598:
dp+=5;
dp[0]=0;
dp+=2;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
dp[5]+=*dp * 1;
dp[7]+=*dp * 1;
dp[0]=0;
if(*dp) goto pc1540;
pc1608:
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc1672;
pc1613:
dp[0]--;
dp+=4;
dp[0]++;
dp+=5;
if(!*dp) goto pc1628;
pc1618:
dp++;
dp[0]++;
dp+=2;
dp[-2]+=*dp * -1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1618;
pc1628:
dp+=-8;
dp[0]++;
dp--;
if(!*dp) goto pc1671;
pc1632:
dp++;
if(!*dp) goto pc1655;
pc1634:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-3;
if(!*dp) goto pc1649;
pc1639:
dp[0]--;
dp+=3;
dp[0]--;
dp+=-13;
dp[0]++;
dp+=11;
dp[2]+=*dp * 1;
dp[0]=0;
dp--;
if(*dp) goto pc1639;
pc1649:
dp++;
dp[-11]+=*dp * 1;
dp[2]+=*dp * -1;
dp[0]=0;
dp+=-2;
if(*dp) goto pc1634;
pc1655:
dp++;
if(!*dp) goto pc1666;
pc1657:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-2;
dp[-11]+=*dp * 1;
dp[2]+=*dp * -1;
dp[0]=0;
dp--;
if(*dp) goto pc1657;
pc1666:
dp++;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=-12;
if(*dp) goto pc1632;
pc1671:
if(*dp) goto pc1613;
pc1672:
dp+=4;
dp[0]=0;
dp+=-4;
if(*dp) goto pc1458;
pc1676:
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc1737;
pc1681:
dp[0]--;
dp+=4;
dp[0]++;
dp++;
dp[0]=0;
dp+=2;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
dp[5]+=*dp * 1;
dp[7]+=*dp * 1;
dp[0]=0;
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc1736;
pc1697:
dp++;
if(!*dp) goto pc1720;
pc1699:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-3;
if(!*dp) goto pc1714;
pc1704:
dp[0]--;
dp+=3;
dp[0]--;
dp+=-13;
dp[0]++;
dp+=11;
dp[2]+=*dp * 1;
dp[0]=0;
dp--;
if(*dp) goto pc1704;
pc1714:
dp++;
dp[-11]+=*dp * 1;
dp[2]+=*dp * -1;
dp[0]=0;
dp+=-2;
if(*dp) goto pc1699;
pc1720:
dp++;
if(!*dp) goto pc1731;
pc1722:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-2;
dp[-11]+=*dp * 1;
dp[2]+=*dp * -1;
dp[0]=0;
dp--;
if(*dp) goto pc1722;
pc1731:
dp++;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=-12;
if(*dp) goto pc1697;
pc1736:
if(*dp) goto pc1681;
pc1737:
dp+=9;
if(!*dp) goto pc1745;
pc1739:
dp+=2;
dp[0]=0;
dp++;
dp[0]=0;
dp+=6;
if(*dp) goto pc1739;
pc1745:
dp+=-9;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp++;
dp[0]=0;
dp+=5;
if(!*dp) goto pc1762;
pc1753:
dp+=5;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
dp[1]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1753;
pc1762:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc1775;
pc1766:
dp+=6;
dp[-5]+=*dp * 1;
dp[0]=0;
dp+=-5;
dp[2]+=*dp * 1;
dp[5]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc1766;
pc1775:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]+=15;
if(!*dp) goto pc1805;
pc1780:
while(*dp)dp+=9;
dp[0]++;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc1780;
pc1805:
dp[0]++;
if(!*dp) goto pc1811;
pc1807:
dp++;
dp[0]++;
dp+=8;
if(*dp) goto pc1807;
pc1811:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc1857;
pc1815:
dp++;
dp[0]--;
dp+=4;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc1841;
pc1822:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-5;
if(!*dp) goto pc1838;
pc1827:
dp[0]--;
dp+=2;
dp[-2]+=*dp * 1;
dp[0]=0;
dp+=-2;
dp[2]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=9;
if(*dp) goto pc1827;
pc1838:
dp+=-8;
while(*dp)dp+=-9;
if(*dp) goto pc1822;
pc1841:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc1850;
pc1845:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-10;
if(*dp) goto pc1845;
pc1850:
dp++;
dp[9]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=8;
if(*dp) goto pc1815;
pc1857:
dp+=-9;
if(!*dp) goto pc1884;
pc1859:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=4;
if(!*dp) goto pc1877;
pc1865:
dp[0]--;
dp+=-4;
dp[0]++;
dp++;
dp[-6]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=4;
if(*dp) goto pc1865;
pc1877:
dp+=-3;
dp[3]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc1859;
pc1884:
dp+=9;
if(!*dp) goto pc1890;
pc1886:
dp++;
dp[0]++;
dp+=8;
if(*dp) goto pc1886;
pc1890:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc1936;
pc1894:
dp++;
dp[0]--;
dp+=5;
dp[-5]+=*dp * 1;
dp[0]=0;
dp+=-5;
if(!*dp) goto pc1920;
pc1901:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-6;
if(!*dp) goto pc1917;
pc1906:
dp[0]--;
dp+=3;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
dp[3]+=*dp * 1;
dp[4]+=*dp * 1;
dp[0]=0;
dp[0]++;
dp+=9;
if(*dp) goto pc1906;
pc1917:
dp+=-8;
while(*dp)dp+=-9;
if(*dp) goto pc1901;
pc1920:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc1929;
pc1924:
dp+=2;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-11;
if(*dp) goto pc1924;
pc1929:
dp+=2;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=-2;
dp[0]++;
dp+=8;
if(*dp) goto pc1894;
pc1936:
dp+=-9;
if(!*dp) goto pc1963;
pc1938:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=4;
if(!*dp) goto pc1956;
pc1944:
dp[0]--;
dp+=-4;
dp[0]++;
dp++;
dp[-6]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=4;
if(*dp) goto pc1944;
pc1956:
dp+=-3;
dp[3]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc1938;
pc1963:
dp+=9;
if(!*dp) goto pc1970;
pc1965:
dp+=4;
dp[-36]+=*dp * 1;
dp[0]=0;
dp+=5;
if(*dp) goto pc1965;
pc1970:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]+=15;
if(!*dp) goto pc1983;
pc1975:
while(*dp)dp+=9;
dp+=-9;
dp[0]--;
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
dp[0]--;
if(*dp) goto pc1975;
pc1983:
dp[0]++;
dp+=21;
dp[0]++;
dp+=-3;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc2060;
pc1990:
dp+=3;
dp[-3]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-3;
if(!*dp) goto pc2019;
pc1996:
dp[0]--;
dp+=3;
dp[0]--;
dp++;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc2018;
pc2004:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-13;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp++;
dp[0]++;
dp--;
if(*dp) goto pc2004;
pc2018:
if(*dp) goto pc1996;
pc2019:
dp[0]++;
dp+=4;
dp[-4]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-4;
if(!*dp) goto pc2050;
pc2026:
dp[0]--;
dp+=4;
dp[0]--;
dp--;
dp[-3]+=*dp * 1;
dp[0]=0;
dp+=-3;
if(!*dp) goto pc2049;
pc2034:
dp[0]--;
dp+=3;
dp[0]++;
dp+=-12;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
dp+=6;
while(*dp)dp+=9;
dp++;
dp[0]=0;
dp[0]++;
dp--;
if(*dp) goto pc2034;
pc2049:
if(*dp) goto pc2026;
pc2050:
dp[0]++;
dp++;
if(!*dp) goto pc2058;
pc2053:
dp[0]--;
dp--;
while(*dp)dp+=9;
dp+=-8;
if(*dp) goto pc2053;
pc2058:
dp+=8;
if(*dp) goto pc1990;
pc2060:
dp+=-9;
while(*dp)dp+=-9;
dp+=2;
dp[0]--;
dp+=2;
dp[-4]+=*dp * 1;
dp[0]=0;
dp+=-4;
if(!*dp) goto pc2076;
pc2069:
dp[0]--;
dp+=4;
dp[0]++;
dp+=-2;
dp[0]=0;
dp+=-2;
if(*dp) goto pc2069;
pc2076:
dp+=2;
if(*dp) goto pc0423;
pc2078:
dp+=-2;
dp[0]++;
dp+=4;
dp[-4]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-4;
if(!*dp) goto pc2093;
pc2086:
dp[0]--;
dp+=4;
dp[0]--;
dp+=-6;
fputc(*dp,stdout);fflush(stdout);
dp+=2;
if(*dp) goto pc2086;
pc2093:
dp+=4;
if(!*dp) goto pc2100;
pc2095:
dp[0]--;
dp+=-7;
fputc(*dp,stdout);fflush(stdout);
dp+=7;
if(*dp) goto pc2095;
pc2100:
dp+=-3;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=3;
if(!*dp) goto pc2128;
pc2114:
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp++;
dp[0]=0;
dp+=3;
if(*dp) goto pc2114;
pc2128:
dp+=-9;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc2136;
pc2132:
dp+=5;
dp[0]=0;
dp+=4;
if(*dp) goto pc2132;
pc2136:
dp+=-9;
while(*dp)dp+=-9;
dp++;
dp[0]+=11;
if(!*dp) goto pc2146;
pc2141:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc2141;
pc2146:
dp+=4;
dp[0]++;
dp+=9;
dp[0]++;
dp+=-14;
while(*dp)dp+=-9;
dp+=7;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
if(!*dp) goto pc2183;
pc2157:
dp[0]--;
dp+=7;
dp[0]++;
dp[0]=0;
dp+=2;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc2182;
pc2165:
dp+=7;
dp[-6]+=*dp * 1;
dp[0]=0;
dp+=-6;
if(!*dp) goto pc2180;
pc2170:
dp[0]--;
dp+=6;
dp[0]++;
dp+=-7;
while(*dp)dp+=-9;
dp+=7;
dp[0]=0;
dp[0]++;
dp+=3;
if(*dp) goto pc2170;
pc2180:
dp+=-10;
if(*dp) goto pc2165;
pc2182:
if(*dp) goto pc2157;
pc2183:
dp+=7;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
if(!*dp) goto pc2248;
pc2188:
dp[0]--;
dp+=7;
dp[0]++;
dp+=2;
if(!*dp) goto pc2203;
pc2193:
dp++;
dp[0]++;
dp+=4;
dp[-4]+=*dp * -1;
dp[0]=0;
dp+=-4;
dp[4]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc2193;
pc2203:
dp+=-2;
dp[0]++;
dp+=-7;
if(!*dp) goto pc2212;
pc2207:
dp+=5;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=-14;
if(*dp) goto pc2207;
pc2212:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc2241;
pc2216:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=7;
if(!*dp) goto pc2234;
pc2222:
dp[0]--;
dp+=-7;
dp[0]++;
dp++;
dp[-3]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=7;
if(*dp) goto pc2222;
pc2234:
dp+=-6;
dp[6]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc2216;
pc2241:
dp+=7;
dp[0]--;
dp+=-4;
dp[0]=0;
dp[0]++;
dp+=-3;
if(*dp) goto pc2188;
pc2248:
dp[0]++;
dp+=7;
dp[-7]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-7;
if(!*dp) goto pc2393;
pc2255:
dp[0]--;
dp+=7;
dp[0]--;
dp+=2;
if(!*dp) goto pc2265;
pc2260:
dp+=5;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=4;
if(*dp) goto pc2260;
pc2265:
dp+=-9;
if(!*dp) goto pc2292;
pc2267:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=7;
if(!*dp) goto pc2285;
pc2273:
dp[0]--;
dp+=-7;
dp[0]++;
dp++;
dp[-3]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=7;
if(*dp) goto pc2273;
pc2285:
dp+=-6;
dp[6]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc2267;
pc2292:
dp++;
dp[0]+=5;
if(!*dp) goto pc2300;
pc2295:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc2295;
pc2300:
dp+=4;
dp[0]++;
dp+=-5;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc2376;
pc2306:
dp+=5;
dp[-5]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-5;
if(!*dp) goto pc2335;
pc2312:
dp[0]--;
dp+=5;
dp[0]--;
dp+=2;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
if(!*dp) goto pc2334;
pc2320:
dp[0]--;
dp+=7;
dp[0]++;
dp+=-16;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp++;
dp[0]++;
dp--;
if(*dp) goto pc2320;
pc2334:
if(*dp) goto pc2312;
pc2335:
dp[0]++;
dp+=7;
dp[-7]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-7;
if(!*dp) goto pc2366;
pc2342:
dp[0]--;
dp+=7;
dp[0]--;
dp+=-2;
dp[-5]+=*dp * 1;
dp[0]=0;
dp+=-5;
if(!*dp) goto pc2365;
pc2350:
dp[0]--;
dp+=5;
dp[0]++;
dp+=-14;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
dp+=6;
while(*dp)dp+=9;
dp++;
dp[0]=0;
dp[0]++;
dp--;
if(*dp) goto pc2350;
pc2365:
if(*dp) goto pc2342;
pc2366:
dp[0]++;
dp++;
if(!*dp) goto pc2374;
pc2369:
dp[0]--;
dp--;
while(*dp)dp+=9;
dp+=-8;
if(*dp) goto pc2369;
pc2374:
dp+=8;
if(*dp) goto pc2306;
pc2376:
dp+=-9;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp+=-3;
dp[0]+=5;
if(!*dp) goto pc2388;
pc2383:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc2383;
pc2388:
dp+=4;
dp[0]--;
dp+=-5;
while(*dp)dp+=-9;
if(*dp) goto pc2255;
pc2393:
dp+=3;
if(*dp) goto pc0082;
pc2395:
dp+=-4;
fputc(*dp,stdout);fflush(stdout);
dp+=10;
if(!*dp) goto pc2403;
pc2399:
dp+=6;
dp[0]=0;
dp+=3;
if(*dp) goto pc2399;
pc2403:
dp+=-9;
while(*dp)dp+=-9;
dp++;
dp[0]+=10;
if(!*dp) goto pc2413;
pc2408:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc2408;
pc2413:
dp+=5;
dp[0]++;
dp+=9;
dp[0]++;
dp+=-15;
while(*dp)dp+=-9;
dp+=8;
dp[-8]+=*dp * 1;
dp[0]=0;
dp+=-8;
if(!*dp) goto pc2450;
pc2424:
dp[0]--;
dp+=8;
dp[0]++;
dp[0]=0;
dp++;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc2449;
pc2432:
dp+=8;
dp[-7]+=*dp * 1;
dp[0]=0;
dp+=-7;
if(!*dp) goto pc2447;
pc2437:
dp[0]--;
dp+=7;
dp[0]++;
dp+=-8;
while(*dp)dp+=-9;
dp+=8;
dp[0]=0;
dp[0]++;
dp+=2;
if(*dp) goto pc2437;
pc2447:
dp+=-10;
if(*dp) goto pc2432;
pc2449:
if(*dp) goto pc2424;
pc2450:
dp+=8;
dp[-8]+=*dp * 1;
dp[0]=0;
dp+=-8;
if(!*dp) goto pc2515;
pc2455:
dp[0]--;
dp+=8;
dp[0]++;
dp++;
if(!*dp) goto pc2470;
pc2460:
dp++;
dp[0]++;
dp+=5;
dp[-5]+=*dp * -1;
dp[0]=0;
dp+=-5;
dp[5]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc2460;
pc2470:
dp--;
dp[0]++;
dp+=-8;
if(!*dp) goto pc2479;
pc2474:
dp+=6;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=-15;
if(*dp) goto pc2474;
pc2479:
dp+=9;
while(*dp)dp+=9;
dp+=-9;
if(!*dp) goto pc2508;
pc2483:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=8;
if(!*dp) goto pc2501;
pc2489:
dp[0]--;
dp+=-8;
dp[0]++;
dp++;
dp[-2]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc2489;
pc2501:
dp+=-7;
dp[7]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc2483;
pc2508:
dp+=8;
dp[0]--;
dp+=-5;
dp[0]=0;
dp[0]++;
dp+=-3;
if(*dp) goto pc2455;
pc2515:
dp[0]++;
dp+=8;
dp[-8]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-8;
if(!*dp) goto pc2664;
pc2522:
dp[0]--;
dp+=8;
dp[0]--;
dp++;
if(!*dp) goto pc2532;
pc2527:
dp+=6;
dp[2]+=*dp * 1;
dp[0]=0;
dp+=3;
if(*dp) goto pc2527;
pc2532:
dp+=-9;
if(!*dp) goto pc2559;
pc2534:
dp++;
dp[0]=0;
dp--;
dp[0]--;
dp+=8;
if(!*dp) goto pc2552;
pc2540:
dp[0]--;
dp+=-8;
dp[0]++;
dp++;
dp[-2]+=*dp * 1;
dp[-1]+=*dp * -1;
dp[0]=0;
dp--;
dp[1]+=*dp * 1;
dp[0]=0;
dp+=8;
if(*dp) goto pc2540;
pc2552:
dp+=-7;
dp[7]+=*dp * 1;
dp[0]=0;
dp--;
dp[0]++;
dp+=-9;
if(*dp) goto pc2534;
pc2559:
dp++;
dp[0]+=5;
if(!*dp) goto pc2567;
pc2562:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc2562;
pc2567:
dp+=5;
dp[0]++;
dp+=27;
dp[0]++;
dp+=-6;
while(*dp)dp+=-9;
dp+=9;
if(!*dp) goto pc2645;
pc2575:
dp+=6;
dp[-6]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-6;
if(!*dp) goto pc2604;
pc2581:
dp[0]--;
dp+=6;
dp[0]--;
dp+=2;
dp[-8]+=*dp * 1;
dp[0]=0;
dp+=-8;
if(!*dp) goto pc2603;
pc2589:
dp[0]--;
dp+=8;
dp[0]++;
dp+=-17;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp[0]++;
dp+=5;
while(*dp)dp+=9;
dp++;
dp[0]++;
dp--;
if(*dp) goto pc2589;
pc2603:
if(*dp) goto pc2581;
pc2604:
dp[0]++;
dp+=8;
dp[-8]+=*dp * -1;
dp[0]=0;
dp[0]++;
dp+=-8;
if(!*dp) goto pc2635;
pc2611:
dp[0]--;
dp+=8;
dp[0]--;
dp+=-2;
dp[-6]+=*dp * 1;
dp[0]=0;
dp+=-6;
if(!*dp) goto pc2634;
pc2619:
dp[0]--;
dp+=6;
dp[0]++;
dp+=-15;
while(*dp)dp+=-9;
dp+=3;
dp[0]=0;
dp[0]++;
dp+=6;
while(*dp)dp+=9;
dp++;
dp[0]=0;
dp[0]++;
dp--;
if(*dp) goto pc2619;
pc2634:
if(*dp) goto pc2611;
pc2635:
dp[0]++;
dp++;
if(!*dp) goto pc2643;
pc2638:
dp[0]--;
dp--;
while(*dp)dp+=9;
dp+=-8;
if(*dp) goto pc2638;
pc2643:
dp+=8;
if(*dp) goto pc2575;
pc2645:
dp+=-9;
while(*dp)dp+=-9;
dp+=4;
dp[0]=0;
dp+=-3;
dp[0]+=5;
if(!*dp) goto pc2657;
pc2652:
dp[0]--;
dp[9]+=*dp * 1;
dp[0]=0;
dp+=9;
if(*dp) goto pc2652;
pc2657:
dp+=5;
dp[0]--;
dp+=27;
dp[0]--;
dp+=-6;
while(*dp)dp+=-9;
if(*dp) goto pc2522;
pc2664:
dp+=3;
if(*dp) goto pc0047;
pc2666:
return *dp;
}


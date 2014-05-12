#include<cstdio>
#include<cstdlib>
#include<cstring>
char str[1005];
char card[15][5];
int cpts[1005];
int cards[1005];
int ha[512];
int hk[512];
int hq[512];
int hj[512];
int main(void)
{
	memset(cpts,0,sizeof(cpts));
	cpts['A'] = 4;
	cpts['K'] = 3;
	cpts['Q'] = 2;
	cpts['J'] = 1;

	while(gets(str)!=NULL)
	{
		int i;
		int N;
		char *cp;
		for(i=0,cp=strtok(str," ");cp!=NULL;cp=strtok(NULL," "),i++)
		{
			strcpy(card[i],cp);
		}
		memset(cards,0,sizeof(cards));
		memset(ha,0,sizeof(ha));	
		memset(hk,0,sizeof(hk));
		memset(hq,0,sizeof(hq));
		memset(hj,0,sizeof(hj));
		int nop = 0;
		int po = 0;
		for(i=0;i<13;i++)
		{
			char a = card[i][0];
			char b = card[i][1];
			nop+=cpts[a];
			cards[b]++;
			if(a=='A')
				ha[b] = 1;
			if(a=='K')
				hk[b] = 1;
			if(a=='Q')
				hq[b] = 1;
			if(a=='J')
				hj[b] = 1;
		}
		char su[4] = {'S','H','D','C'};
		int stop[4] = {};
		for(i=0;i<4;i++)
		{
			if(hk[su[i]]==1&&cards[su[i]]<=1)
				nop--;
			if(hq[su[i]]==1&&cards[su[i]]<=2)
				nop--;
			if(hj[su[i]]==1&&cards[su[i]]<=3)
				nop--;
			if(ha[su[i]]==1)
				stop[i] = 1;
			if(hk[su[i]]==1&&cards[su[i]]>1)
				stop[i] = 1;
			if(hq[su[i]]==1&&cards[su[i]]>2)
				stop[i] = 1;
		}
		int ok = 0;
		if(nop>=16)
		{
			ok = 1;
			for(i=0;i<4;i++)
				if(stop[i]==0)
					ok=  0;
		
		}
		if(ok==1)
		{
			printf("BID NO-TRUMP\n");
			continue;
		}
		po = nop;
		for(i=0;i<4;i++)
		{
			if(cards[su[i]]==2)
				po++;
			if(cards[su[i]]<=1)
				po+=2;
		}
		//printf("%d %d\n",nop,po);
		if(po<14)
		{
			printf("PASS\n");
		}
		else
		{
			int mmax = 0;
			int maxp = -1;
			for(i=0;i<4;i++)
				if(cards[su[i]]>mmax)
				{
					mmax = cards[su[i]];
					maxp = i;
				}
			printf("BID %c\n",su[maxp]);
		}
	}

	return 0;
}

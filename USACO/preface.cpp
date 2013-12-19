/*
ID: zxc10801
PROG: preface
LANG: C++

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>

char cc[10] = "IVXLCDM";

int nn[10][4005];
int aa[8] = {1,5,10,50,100,500,1000,5000};
int main()
{
	memset(nn,0,sizeof(nn));
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int i,j,k;
	for(i=1;i<=4000;i++)
	{
		int tmp = i;
		if((tmp+1)%5==0&&(tmp+1)%10!=0)
		{
			nn[0][i] ++;
			nn[1][i] ++;
		}
		else if((tmp+1)%10==0)
		{
			nn[0][i]++;
			nn[2][i]++;
		}
		else
			nn[0][i]+=tmp%5;
		if((tmp+1)%10!=0)
			nn[1][i]+=(tmp%10)/5;
		
		tmp/=10;
		if((tmp+1)%5==0&&(tmp+1)%10!=0)
		{
			nn[2][i] ++;
			nn[3][i] ++;
		}
		else if((tmp+1)%10==0)
		{
			nn[2][i]++;
			nn[4][i]++;
		}
		else
			nn[2][i]+=tmp%5;
		if((tmp+1)%10!=0)
			nn[3][i]+=(tmp%10)/5;
		
		tmp/=10;
		if((tmp+1)%5==0&&(tmp+1)%10!=0)
		{
			nn[4][i] ++;
			nn[5][i] ++;
		}
		else if((tmp+1)%10==0)
		{
			nn[4][i]++;
			nn[6][i]++;
		}
		else
			nn[4][i]+=tmp%5;
		if((tmp+1)%10!=0)
			nn[5][i]+=(tmp%10)/5;
		
		tmp/=10;

		nn[6][i]+=tmp%5;
	}
	
	int N;
	scanf("%d",&N);
	for(i=0;i<7;i++)
	{
		for(j=1;j<=N;j++)
			nn[i][j]+=nn[i][j-1];
	}
	
	int np = -1;
	for(i=6;i>=0;i--)
		if(nn[i][N]!=0)
	{
		np = i;
		break;
	}
	for(i=0;i<=np;i++)
		printf("%c %d\n",cc[i],nn[i][N]);
	
	return 0;
}
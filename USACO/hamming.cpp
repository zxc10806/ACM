/*
ID: zxc10801
TASK: hamming
LANG: C++

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
int N,B,D;
int sol[105];
int sn;
int min;
void back(int val,int k)
{
	int i,j;
	if(val>min)
		return;
	if(k==B)
	{
		int ok = 1;
		for(i=0;i<sn;i++)
		{
			int A = sol[i];
			int C = val;
			int tmp = 0;
			for(j=0;j<B;j++)
			{
				if(A%2!=C%2)
					tmp++;
				A/=2;
				C/=2;
			}
			if(tmp<D)
				ok = 0;
		}
		if(ok==1&&val<min)
			min = val;
		return ;
	}
	back(val*2,k+1);
	back(val*2+1,k+1);
}


int main(void)
{
	
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d %d %d",&N,&B,&D);
	int i,j,k;
	int tmp;
	for(i=0;i<N;i++)
	{
		min = 1e8;
		sn = i;
		back(0,0);
		
		sol[i] = min;
	}
	for(i=0;i<N;i++)
	{
		if(i%10==0&&i!=0)
			printf("\n");
		if(i%10==0)
			printf("%d",sol[i]);
		else
		printf(" %d",sol[i]);
		
	}
	printf("\n");
	return 0;
}

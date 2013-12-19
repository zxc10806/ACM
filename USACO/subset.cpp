/*
ID: zxc10801
PROG: subset
LANG: C++

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#define LL long long int
LL V[1005];
int a[100];
int main()
{
	int all = 0;
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	int N;
	int i,j,k;
	a[0] = 0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		a[i] = i;
		all+=i;
		
	}
	if(all%2!=0)
		printf("0\n");
	else
	{
		memset(V,0,sizeof(V));
		for(i=1;i<=N;i++)
		{	for(j=all;j>i;j--)
			V[j]+=V[j-i];
		 	V[i]++;
		}
		printf("%lld\n",V[all/2]/2);
	}
	
	return 0;
}
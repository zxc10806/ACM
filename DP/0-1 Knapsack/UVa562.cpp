#include<cstdio>
#include<cstdlib>
#include<cstring>

int V[50005];

int main()
{
	int n,m;
	scanf("%d",&n);
	int i,j,k;
	int all;
	int x;
	while(n--)
	{
		
		all = 0;
		memset(V,0,sizeof(V));
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			for(j=50000;j>x;j--)
				V[j]|=V[j-x];
			V[x] = 1;
			all+=x;
		}
		V[0] = 1;
		for(i=all/2;i>=0;i--)
			if(V[i]==1)
			{
				printf("%d\n",all-2*i);
				break;
			}
		
		
		
		
		
	}
	
	return 0;
}
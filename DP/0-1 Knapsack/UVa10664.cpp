#include<cstdio>
#include<cstdlib>
#include<cstring>

int V[505];
char str[10005];
int main()
{
	int n,m;
	scanf("%d",&n);
	int i,j,k;
	int all;
	int x;
	getchar();
	char *p;
	while(n--)
	{
	
		gets(str);
		memset(V,0,sizeof(V));
		all = 0;
		for(p=strtok(str," ");p!=NULL;p = strtok(NULL," "))
		{
			x = atoi(p);
			for(j=500;j>x;j--)
			{
				V[j]|=V[j-x];
			}
			V[x] = 1;
			all+=x;
		}
		if(all%2||V[all/2]==0)
			printf("NO\n");
		else
			printf("YES\n");
		
	}	
	
	return 0;
}
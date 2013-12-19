/*
ID: zxc10801
LANG: C++
TASK: holstein

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>


int Vn;
int V[26];
int Gn;
int G[16][26];

int ans[16];
int s[16];
int minp;
void back(int k,int t[],int sn)
{
	
	
	if(k>Gn+1)
		return ;
	
	int i,j;
	int ok = 1;
	for(i=1;i<=Vn;i++)
	{
		
		if(t[i]<V[i])
		ok = 0;
	}
	if(ok==1)
	{
		

		if(sn<minp)
		{
			minp  = sn;
			for(i=0;i<minp;i++)
				ans[i] = s[i];
		}
		else if(sn==minp)
		{
			int ch = 0;
			for(i=0;i<minp;i++)
				if(ans[i]<s[i])
				{
					ch = 0;
					break;
				}
				else if(ans[i]>s[i])
				{
					ch = 1;
					break;
				}
			if(ch==1)
				for(i=0;i<minp;i++)
				ans[i] = s[i];
		}
	}
	
	if(sn+1>minp)
		return ;
	
	s[sn] = k;
	for(i=1;i<=Vn;i++)
		t[i]+=G[k][i];
	back(k+1,t,sn+1);
	for(i=1;i<=Vn;i++)
		t[i]-=G[k][i];
	
	back(k+1,t,sn);
	
}

int tt[26];
int main(void)
{
	
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	
	
	int i,j,k;
	
	scanf("%d",&Vn);
	
	for(i=1;i<=Vn;i++)
		scanf("%d",&V[i]);
	scanf("%d",&Gn);
	for(i=1;i<=Gn;i++)
		for(j=1;j<=Vn;j++)
		scanf("%d",&G[i][j]);
		
	memset(tt,0,sizeof(tt));
	
	minp = 100;
	back(1,tt,0);
		
	printf("%d",minp);
	for(i=0;i<minp;i++)
		printf(" %d",ans[i]);
	printf("\n");
	
	return 0;
}
/*
ID: zxc10801
LANG: C++
PROG: runround

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;


int ans[10005];
int an;


int s[15];
int used[15];
void check(int n)
{
	int i,j,k;
	int t[15] = {};
	int ok = 1;
	k = 0;
	while(1)
	{
		j = (k+s[k])%n;
		if(t[j]==1)
			break;
		t[j] = 1;
		k = j;
	}
	for(i=0;i<n;i++)
		if(t[i]==0)
		return ;
	int x = 0;
	for(i=0;i<n;i++)
	{
		x*=10;
		x+=s[i];
	}
	ans[an++] = x;
}
void ran(int n,int k)
{
	if(n==k)
	{
		check(n);
		return ;
	}
	int i,j;
	for(i=1;i<10;i++)
		if(used[i]==0)
		{
			used[i] = 1;
			s[k] = i;
			ran(n,k+1);
			used[i] = 0;
		}
	
}


int main(void)
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	an = 0;
	int i,j,k;
	for(i=1;i<=9;i++)
	{
		memset(used,0,sizeof(used));
		ran(i,0);
	}
	
	int s;
	scanf("%d",&s);
	
	sort(ans,ans+an);
	for(i=0;i<an;i++)
		if(s<ans[i])
		{
			printf("%d\n",ans[i]);
			break;
		}
	
	
	
	return 0;
}
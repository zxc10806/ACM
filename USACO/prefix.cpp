/*
ID: zxc10801
LANG: C++
PROG: prefix

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char str[200005];
char prim[205][15];
char tmp[105];
int pn = 0;
int V[200005];


int lpre(int m)
{
	if(m<0)
		return -1;
	int i,j,k;
	if(V[m]!=0)
		return V[m];
	V[m] = -1;
	for(i=0;i<pn;i++)
		if(lpre(m-strlen(prim[i]))==1)
		{
			int ok = 1;
			int l = strlen(prim[i]);
			for(j=0;j<l;j++)
				if(prim[i][j]!=str[m-l+j])
					ok = 0;
			if(ok==1)
			{
				V[m] = 1;
				break;
			}
		}
	return V[m];
}

int main(void)
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	
	int i,j,k;
	while(1)
	{
		scanf("%s",tmp);
		if(tmp[0]=='.')
			break;
		strcpy(prim[pn],tmp);
		pn++;
	}
	memset(str,0,sizeof(str));
	while(~scanf("%s",tmp))
	{
		strcat(str,tmp);
	}
	
	int l = strlen(str);
	memset(V,0,sizeof(V));
	V[0] = 1;
	
	
	for(i=l;i>=0;i--)
	if(lpre(i)==1)
	{
		printf("%d\n",i);
		break;
	}
	
	
	
	return 0;
}
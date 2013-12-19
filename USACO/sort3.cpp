/*
ID: zxc10801
LANG: C++
TASK: sort3

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int v[3];
int a[1005];
int nn[3];
int ap[3][3];
int main(void)
{
	
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	int n;
	v[0] = v[1] = v[2]  = 1;
	int i,j,k;
	memset(ap,0,sizeof(ap));
	nn[0] = nn[1] = nn[2] = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		v[a[i]-1]++;
	}
	int c[1005];
	k = 0;
	for(i=0;i<3;i++)
	{
		for(j = 1;j<v[i];j++)
			c[k++] = i+1;
	}
	int ans = 0;
	for(i=0;i<n;i++)
		if(a[i]!=c[i])
		{
			
			j = a[i]-1;
			ap[j][c[i]-1]++;	
			
		}
	
	for(i=1;i<3;i++)
	{
		
		ap[0][i] -= ap[i][0];
	
		ans+=ap[i][0];
		if(ap[0][i]<0)
		{
			
			if(i==1)
				ap[1][2]+=(-1*ap[0][i]);
			else
				ap[2][1]+=(-1*ap[0][i]);
		}
		
	}
	
	ans+=max(ap[2][1],ap[1][2]);
	
	printf("%d\n",ans);
	
	return 0;
}
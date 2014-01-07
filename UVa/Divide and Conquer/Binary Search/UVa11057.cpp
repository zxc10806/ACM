#include<cstdio>
#include<cstdlib>
#include<cstring>

int cmp(const void *a,const void *b)
{
	int x = *((int*)a);
	int y = *((int*)b);
	
	
	return x-y;
	
}

int x[10005];
int main(void)
{
	int i,j;
	int N,M;
	int a,b;
	while(~scanf("%d",&N))
	{
		for(i=0;i<N;i++)
			scanf("%d",&x[i]);
		scanf("%d",&M);
		qsort(x,N,sizeof(x[0]),cmp);
		a = 0;
		b = 1e8;
		
		for(i=0;i<N;i++)
		{
			int tmp = M - x[i];
			if(tmp<x[i])
				continue;
			int l,r,mid;
			l = 0;
			r = N-1;
			while(l<r)
			{
				mid = (l+r)/2;
				if(x[mid]<tmp)
					l = mid+1;
				else
					r = mid;
			}
			if(x[r]==tmp)
			{
				if(tmp-x[i]<b-a)
				{
					a = x[i];
					b = tmp;
				}
			}
		}
		
		printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);
		
		
	}
	
	return 0;
}
/*
ID: zxc10801
LANG: C++
PROG: lamps

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#define SS struct S

SS
{
	int a[101];	
};

SS ans[1005];
int an;
int on[105]={};
int off[105]={};
int state[105];
int N;
int cmp(const void *a,const void *b)
{
	SS x = *((SS*)a);
	SS y = *((SS*)b);
	int i;
	for(i=0;i<N;i++)
		if(x.a[i]!=y.a[i])
		return x.a[i]-y.a[i];
	
	
}
void check(int s[],int N)
{
		int i;
		int ok = 1;
		for(i=0;i<N;i++)
		{
			if(on[i]==1&&s[i]==0)
			ok = 0;
			if(off[i]==1&&s[i]==1)
			ok = 0;
		}
		if(ok==1)
		{
			for(i=0;i<N;i++)
				ans[an].a[i] = s[i];
			an++;
		}
}

int main(void)
{
	int i,j,k,l,i1,j1;
	int C;
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	an = 0;
	scanf("%d",&N);
	scanf("%d",&C);
	
	int x;
	while(~scanf("%d",&x)&&x!=-1)
	{
		on[x-1] = 1;
		
	}
	while(~scanf("%d",&x)&&x!=-1)
	{
		off[x-1] = 1;
		
	}
	if(C%2==0)
	{
		memset(state,0,sizeof(state));
		for(i=0;i<N;i++)
		{
			state[i] = !state[i];
			
		}
		check(state,N);
	}
	if(C>=1&&C%2==1)
	{
		memset(state,0,sizeof(state));
		check(state,N);
		
		memset(state,0,sizeof(state));
		
		for(i=0;i<N;i++)
			if(i%2)
			state[i] = !state[i];
		check(state,N);
		memset(state,0,sizeof(state));
		
		for(i=0;i<N;i++)
			if(i%2==0)
			state[i] = !state[i];
		check(state,N);
		memset(state,0,sizeof(state));
		for(i=0;i<N;i++)
			if((i+1)%3==1)
			state[i] = 1;
		for(i=0;i<N;i++)
			state[i] = !state[i];
		check(state,N);
	}
	if(C>=2&&C%2==0)
	{
		for(i=0;i<4;i++)
			for(j=i+1;j<4;j++)
			{
				memset(state,0,sizeof(state));
				switch(i)
				{
					case 0:
					for(i1=0;i1<N;i1++)
						state[i1] = !state[i1];
					break;
					case 1:
					for(i1=0;i1<N;i1++)
						if(i1%2)
						state[i1] = !state[i1];
					break;
					case 2:
					for(i1=0;i1<N;i1++)
						if(i1%2==0)
						state[i1] = !state[i1];
					break;
					case 3:
					for(i1=0;i1<N;i1++)
						if((i1+1)%3==1)
						state[i1] = !state[i1];
					break;
				}
				switch(j)
				{
					case 0:
					for(i1=0;i1<N;i1++)
						state[i1] = !state[i1];
					break;
					case 1:
					for(i1=0;i1<N;i1++)
						if(i1%2)
						state[i1] = !state[i1];
					break;
					case 2:
					for(i1=0;i1<N;i1++)
						if(i1%2==0)
						state[i1] = !state[i1];
					break;
					case 3:
					for(i1=0;i1<N;i1++)
						if((i1+1)%3==1)
						state[i1] = !state[i1];
					break;
				}
				for(i1=0;i1<N;i1++)
					state[i1] = !state[i1];
				check(state,N);
			}
		
		
	}
	if(C>=3&&C%2==1)
	{
		for(i=0;i<4;i++)
			for(j=i+1;j<4;j++)
				for(k=j+1;k<4;k++)
				{
					memset(state,0,sizeof(state));
					switch(i)
				{
					case 0:
					for(i1=0;i1<N;i1++)
						state[i1] = !state[i1];
					break;
					case 1:
					for(i1=0;i1<N;i1++)
						if(i1%2)
						state[i1] = !state[i1];
					break;
					case 2:
					for(i1=0;i1<N;i1++)
						if(i1%2==0)
						state[i1] = !state[i1];
					break;
					case 3:
					for(i1=0;i1<N;i1++)
						if((i1+1)%3==1)
						state[i1] = !state[i1];
					break;
				}
			switch(j)
				{
					case 0:
					for(i1=0;i1<N;i1++)
						state[i1] = !state[i1];
					break;
					case 1:
					for(i1=0;i1<N;i1++)
						if(i1%2)
						state[i1] = !state[i1];
					break;
					case 2:
					for(i1=0;i1<N;i1++)
						if(i1%2==0)
						state[i1] = !state[i1];
					break;
					case 3:
					for(i1=0;i1<N;i1++)
						if((i1+1)%3==1)
						state[i1] = !state[i1];
					break;
				}
			switch(k)
				{
					case 0:
					for(i1=0;i1<N;i1++)
						state[i1] = !state[i1];
					break;
					case 1:
					for(i1=0;i1<N;i1++)
						if(i1%2)
						state[i1] = !state[i1];
					break;
					case 2:
					for(i1=0;i1<N;i1++)
						if(i1%2==0)
						state[i1] = !state[i1];
					break;
					case 3:
					for(i1=0;i1<N;i1++)
						if((i1+1)%3==1)
						state[i1] = !state[i1];
					break;
				}
			for(i1=0;i1<N;i1++)
				state[i1] = !state[i1];
				}
		
		
	}
	if(C>=4&&C%2==0)
	{
		memset(state,0,sizeof(state));
		for(i1=0;i1<N;i1++)
			state[i1] = !state[i1];
		for(i1=0;i1<N;i1++)
		if(i1%2)
		state[i1] = !state[i1];
		for(i1=0;i1<N;i1++)
		if(i1%2==0)
			state[i1] = !state[i1];
			for(i1=0;i1<N;i1++)
						if((i1+1)%3==1)
						state[i1] = !state[i1];
			for(i1=0;i1<N;i1++)
				state[i1] = !state[i1];
			check(state,N);
	}
	qsort(ans,an,sizeof(ans[0]),cmp);
	for(i=0;i<an;i++)
	{
		for(j=0;j<N;j++)
			printf("%d",ans[i].a[j]);
		printf("\n");
	}
	if(an==0)
		printf("IMPOSSIBLE\n");
	return 0;
}
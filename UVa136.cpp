#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long int

lint f[1505];

int main(void)
{
		int i,j,k;
		int p2,p3,p5;
		lint n2,n3,n5;
		
		p2 = p3 = p5 = 1;
		f[1] = 1;
		
		for(i=2;i<=1500;i++)
		{
			n2 = f[p2]*2;
			while(n2<=f[i-1])
			{
				p2++;
				n2 = f[p2]*2;
			}
			n3 = f[p3]*3;
			while(n3<=f[i-1])
			{
				p3++;
				n3 = f[p3]*3;
			}
			n5 = f[p5]*5;
			while(n5<=f[i-1])
			{
				p5++;
				n5 = f[p5]*5;
			}
			lint an = n2;
			if(an>n3)
				an = n3;
			if(an>n5)
				an = n5;
			f[i] = an;
		}
		printf("%lld\n",f[1500];

		return 0;
}

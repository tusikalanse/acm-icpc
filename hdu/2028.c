#include <stdio.h>
int gcd(int a,int b) {return a%b?gcd(b,a%b):b;}
int main(void)
{
	int n,t;
	while(EOF!=scanf("%d",&n))
	{
		int out=0;
		int i=0;
		while(i<n)
		{
			scanf("%d",&t);
			out=(i?(out/gcd(out,t))*t:t);
			i++;
		}
		printf("%d\n",out);
	}
	return 0;
}


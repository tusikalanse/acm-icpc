#include <stdio.h>
int fool(int x);
int main(void)
{
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		if((fool(a)==b)&&(a==fool(b)))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
int fool(int x)
{
	int sum=0;
	for(int i=1;i<x;i++)
	{
		if(x%i==0)
			sum+=i;
	}
	return sum;
}

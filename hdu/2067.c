#include <stdio.h>
unsigned long long list[37]={1,1};
int main(void)
{
	int n,count=0;
	for(int i=2;i<=36;i++)
	{
		list[i]=0;
		for(int j=0;j<i;j++)
			list[i]+=list[j]*list[i-j];
	}
	while(scanf("%d",&n)&&n!=-1)
	{
		count++;
		printf("%d %d %llu\n",count,n,2*list[n+1]);
	}
	return 0;
}

#include <stdio.h>
int main(void)
{
	int n;
	long long list[52]={0,1,1};
	for(int i=3;i<52;i++)
		list[i]=list[i-1]+list[i-2];
	while(scanf("%d",&n)&&n!=-1)
	{
		printf("%lld\n",list[n]);
	}
	return 0;
}


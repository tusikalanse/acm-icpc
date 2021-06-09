#include <stdio.h>
int main(void)
{
	int n,a,b;
	long long list[52]={1,1};
	scanf("%d",&n);
	for(int i=2;i<52;i++)
		list[i]=list[i-1]+list[i-2];
	while(n--)
	{
		scanf("%d %d",&a,&b);
		printf("%lld\n",list[b-a]);
	}
	return 0;
}


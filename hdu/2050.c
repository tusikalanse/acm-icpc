#include <stdio.h>
int list[10005]={0,2};
int main(void)
{
	int n,m;
	for(int i=2;i<=10005;i++)
		list[i]=list[i-1]+1+4*(i-1);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",list[m]);
	}
	return 0;
}


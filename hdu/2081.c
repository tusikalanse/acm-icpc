#include <stdio.h>
int main(void)
{
	int n;
	char num[12];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(num);
		printf("6");
		puts(num+6);
	}
	return 0;
}


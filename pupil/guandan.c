#include <stdio.h>
int main(void)
{
	int n, a, b, c, d;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a>b)
		printf("岩巨\n");
		else if (b>c)
		printf("刘比尔\n");
		else if (c>d)
		printf("进进\n");
		else if (d>a)
		printf("高书记\n");
		else if (a==27)
		printf("101掼蛋锦标赛现在开始！\n");
		else printf("祝秀军，牛逼！\n");
	}
	return 0;
}


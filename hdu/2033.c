#include <stdio.h>
int main(void)
{
	int a,b,c,n,ah,am,as,bh,bm,bs;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d %d %d",&ah,&am,&as,&bh,&bm,&bs);
		c=(as+bs)%60;
		b=(am+bm+(as+bs)/60)%60;
		a=ah+bh+(am+bm+(as+bs)/60)/60;
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}


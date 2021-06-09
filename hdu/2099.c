#include <stdio.h>
int main(void)
{
	int m,n;
	while(scanf("%d %d",&m,&n)&&(m||n))
	{
		int list[100];
		int t=0,p=100;
		for(int i=0;i<100;i++)
		{
			list[i]=-1;
			if((m*100+i)%n==0)
			{
				list[t]=i;
				t++;
			}
		}
		for(int i=0;i<100;i++)
		{
			if(-1==list[i])
			{
				p=i;
				break;
			}
		}
		for(int i=0;i<p;i++)
		{
			if(list[i]<10)
				putchar('0');
			printf("%d%s",list[i],i==p-1?"":" ");
		}
		printf("\n");
	}
	return 0;
}


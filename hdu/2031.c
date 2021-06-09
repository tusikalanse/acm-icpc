#include <stdio.h>
void turn(int n,int r);
int main(void)
{
	int n,r;
	while(~scanf("%d %d",&n,&r))
	{	
		if(n<0)
			{
				printf("-");
				n=-n;
			}
		turn(n,r);
		printf("\n");
	}
	return 0;
}
void turn(int n,int r)
{
	if(n<r)
		printf("%c",n>9?n+55:n+48);
	else
	{
		turn(n/r,r);
		printf("%c",n%r>9?n%r+55:n%r+48);
	}
}

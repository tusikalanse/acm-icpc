#include <stdio.h>
int main(void)
{
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		int count=0;
		int x;
		while((x=getchar())!='\n')
			if(x>='0'&&x<='9')
				count++;
		printf("%d\n",count);
	}
	return 0;
}


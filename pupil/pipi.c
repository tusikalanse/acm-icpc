#include <stdio.h>
char stack[1000002];
int main(void)
{	
	int n,ptr;
	char ch;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		ptr = 0;
		while((ch = getchar()) != '\n')
		{
			stack[ptr] = ch;
			if(ptr && stack[ptr]==stack[ptr-1])
				ptr--;
			else
				ptr++;
		}
		stack[ptr] = '\0';
		printf("%s\n",stack);
	}
	return 0;
}


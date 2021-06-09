#include <stdio.h>

int main(void)
{
	int c, m ,n;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d %d", &n, &m);
		if(n%(m+1)) printf("Grass\n");
		else printf("Rabbit\n");
	}
	return 0;
}


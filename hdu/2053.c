#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	while(~scanf("%d", &n)){
		if((int)sqrt(n)*(int)sqrt(n) == n)
			puts("1");
		else puts("0");
	}
	return 0;
}


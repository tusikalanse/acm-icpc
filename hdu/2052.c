#include <stdio.h>

int main()
{
	int n, m;
	while(~scanf("%d %d", &n, &m)){
		for(int i = 0; i<n+2; i++) putchar((i == 0 || i == n+1)?'+':'-');
		puts("");
		for(int j = 0; j<m; j++){
		for(int i = 0; i<n+2; i++) putchar((i == 0 || i == n+1)?'|':' ');
			puts("");
		}		
		for(int i = 0; i<n+2; i++) putchar((i == 0 || i == n+1)?'+':'-');
		puts("");
		
		puts("");
	}
	return 0;
}


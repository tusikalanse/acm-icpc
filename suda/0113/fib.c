#include <stdio.h>

int main(){
	int fib[100] = {0, 1};
	for (int i = 2; i<101; i++)
		fib[i] = fib[i-1] + fib[i-2];
	int n;
	while(scanf("%d", &n)) printf("fib(%d)=%d\n" ,n, fib[n]);
	return 0;
}

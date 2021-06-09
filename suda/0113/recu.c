#include <stdio.h>

int fib(int n);
int main(){
	int n;
	while(1){
		scanf("%d", &n);
		printf("%d\n", fib(n));
		}
	return 0;
}

int fib(int n){
	if (n<3) return 1;
	return fib(n-1) + fib(n-2);
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	int fib[20] = {1,1};
	for(int i = 2; i<20; i++)
		fib[i] = fib[i-1] + fib[i-2];
	int n;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++){
		int flag = 0;
		for(int j = 0; j<20; j++){
			if(fib[j] == i){
				flag = 1; 
				break;
			}
		}
		putchar(flag?'O':'o');
	}
	puts("");
	return 0;
}
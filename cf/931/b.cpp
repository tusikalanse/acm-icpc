#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	a--;
	b--;
	int c = a ^ b;
	int d = 0;
	while(c){
		d++;
		c >>= 1;
	}
	if(1 << d == n) puts("Final!");
	else printf("%d\n", d);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int n, a, pos, neg;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		pos += a > 0;
		neg += a < 0;
	}
	if(pos * 2 >= n) {
		puts("1");
	}
	else if(neg * 2 >= n) {
		puts("-1");
	}
	else {
		puts("0");
	}
	return 0;
}
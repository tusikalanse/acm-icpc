#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

int n, m;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= 500; ++i) {
		putchar('5');
	}
	putchar('\n');
	for(int i = 1; i <= 499; ++i)
		putchar('4');
	putchar('5');
	putchar('\n');
	return 0;
}
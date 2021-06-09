#include <bits/stdc++.h>
using namespace std;

int mn[1000], mx[1000];

int main() {
	int n, m, smn, smx;
	cin >> n >> m;
	smx = smn = m;
	if(n == 1 && m == 0) {
		puts("0 0");
		return 0;
	}
	if(m > 9 * n || m == 0) {
		puts("-1 -1");
		return 0;
	}
	if(n == 1) {
		printf("%d\n", m);
	}
	else { 
		putchar(max(1, smn - 9 * (n - 1)) + '0');
		smn -= max(1, smn - 9 * (n - 1));
		for(int i = 1; i < n; ++i) {
			putchar(max(0, smn - 9 * (n - 1 - i)) + '0');
			smn -= max(0, smn - 9 * (n - 1 - i));
		}
	}
	putchar(' ');
	for(int i = 0; i < n; ++i) {
		putchar(min(9, smx) + '0');
		smx -= min(9, smx);
	}
	puts("");
	return 0;
}
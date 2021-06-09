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


int n, m, a = 0, b = 0, c = 0, d = 0, p, q;
char ch;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> ch;
			if(ch == 'B') {
				if(a == 0)
					a = i;
				b = i;
				if(c == 0)
					c = j;
				d = j;
			}
		}
	}
	p = a + b >> 1;
	q = c + d >> 1;
	cout << p << ' ' << q << endl;

	return 0;
}
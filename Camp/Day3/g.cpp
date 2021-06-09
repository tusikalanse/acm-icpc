#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int p[N], q[N], n, pos, cnt, tot;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &q[i]);
	}
	pos = tot = n;
	for(int i = 1; i <= n; ++i) {
		if(p[q[i]] == 0) {
			p[q[i]] = ++cnt;
			for(; p[pos] == 0 && pos > 0; pos--) {
				p[pos] = tot--; 
			}
			pos = q[i] - 1;
		}
	}
	for(int i = 1; i <= n; ++i) 
		printf("%d%c", p[i], " \n"[i == n]);
	return 0;
}
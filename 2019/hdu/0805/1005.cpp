#include <bits/stdc++.h>
using namespace std;

int a[25], T, n, k, b[25], vis[25][50], N = 25, s, ss, mx, mn;
long long f[25], tmp;

void get_a() {
	int x = 0, s = 0, p = 1;
	for(int i = 1; i < n; ++i) {
		s += b[i];
		if(s > x) {
			p = 1 + i;
			x = s;
		}
	}
	a[p] = n;
	for(int i = p + 1; i <= n; ++i) {
		a[i] = b[i - 1] + a[i - 1];
	}
	for(int i = p - 1; i > 0; --i) {
		a[i] = a[i + 1] - b[i];
	}
}

int main() {
	f[0] = f[1] = 1;
	for(int i = 2; i <= 20; ++i)
		f[i] = f[i - 1] * i;
	scanf("%d", &T);
	while(T--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &k);
		vis[0][N] = 1; s = 0; mx = 0; mn = 0;
		for(int i = 1; i < n; ++i) {
			for(int j = 1 - n; j <= n - 1; ++j) {
				if(vis[i - 1][N - j] || j == 0) continue;
				ss = s + j;
				bool flag = 0;
				for(int l = N - n; l <= N + n; ++l) {
					if(vis[i - 1][l] && (abs(l + j - N) >= n || l + j == N))
						flag = 1;
				}
				if(flag) continue;
				if(i == 1)
					tmp = f[n - i - 1] * (n - abs(ss));
				else 
					tmp = f[n - i - 1] * (n - max(max(abs(mx), abs(mn)), max(max(abs(ss - mx), abs(ss - mn)), max(abs(mx - mn), abs(ss)))));
				if(tmp >= k) {
					b[i] = j;
					s += j;
					int sp = 0;
					vis[i][sp + N] = 1;
					for(int l = i; l; --l) {
						sp += b[l];
						vis[i][sp + N] = 1;
					}
					mx = max(mx, ss);
					mn = min(mn, ss);	
					break;
				}
				else {
					k -= tmp;
				}
			}
		}
		get_a();
		for(int i = 1; i <= n; ++i)
			printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}
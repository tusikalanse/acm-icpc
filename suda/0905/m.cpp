#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, T, x, y, k;
int p, q;
int lis[N][2];

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

unordered_map<int, int> vis[N];

void judge(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= n) return;
	if(vis[x][y]) return;
	q--;
	if(x + y >= n - 1)
		p--;
}

void calc(int x, int y) {
	int t;
	if((x == 0 && y == 0) || (x == 0 && y == n - 1) || (x == n - 1 && y == 0) || (x == n - 1 && y == n - 1))
		t = 3;
	else if(x == 0 || x == n - 1 || y == 0 || y == n - 1)
		t = 4;
	else 
		t = 5;
	q -= t;
	if(x + y >= n - 1)
		p -= t;
	judge(x - 1, y);
	judge(x + 1, y);
	judge(x, y - 1);
	judge(x, y + 1);
}

void solve() {
	for(int i = 0; i < k; ++i) 
		calc(lis[i][0], lis[i][1]);
}

int main() {
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; ++i)
			vis[i].clear();
		for(int i = 0; i < k; ++i) {
			scanf("%d%d", &x, &y);
			vis[x][y] = 1;
			lis[i][0] = x, lis[i][1] = y;
		}
		if(n == 1) 
			p = q = 1;
		else if(n == 2)
			q = 12, p = 9;
		else 
			q = 12 + 4 * (4 * n - 8) + 5 * (n * n - 4 * n + 4), p = 9 + 4 * (2 * n - 4) + 5 * (n - 1) * (n - 2) / 2;
		solve();
		int g = gcd(p, q);
		p /= g, q /= g;
		printf("Case #%d: %d/%d\n", ++cas, p, q);
	}
	return 0;
}
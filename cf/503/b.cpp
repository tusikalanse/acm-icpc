#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1010;
int a[1010], vis[1010], ans[1010], n;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		int p = a[i];
		while(!vis[p]) {
			vis[p] = 1;
			p = a[p];
		}
		ans[i] = p;
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
vector<int> d[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, t;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> k;
		while(k--) {
			cin >> t;
			d[t].push_back(i);
		}
	}
	t = 0;
	long long res = 1;
	sort(d + 1, d + m + 1);
	for(int i = 1; i <= m; ++i) {
		if(d[i] == d[i - 1])
			res = res * (++t) % mod;
		else 
			t = 1;
	}
	cout << res << endl;
	return 0;
}
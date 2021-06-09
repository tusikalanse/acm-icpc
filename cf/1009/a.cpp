#include <bits/stdc++.h>
using namespace std;

int c[1010];

int main() {
	int n, m, ans = 0, t;
	cin >> n >> m;
	queue<int> a;
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	for(int i = 0; i < m; ++i) {
		cin >> t;
		a.push(t);
	}
	for(int i = 0; i < n; ++i) {
		if(a.empty())
			break;
		if(a.front() >= c[i]) {
			ans++;
			a.pop();
		}
	}
	cout << ans << endl;

	return 0;
}
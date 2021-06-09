#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3010;

int n, m, p[N], c[N], cnt[N], vis[N];
LL ans, tmp;


int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i] >> c[i];
		if(p[i] != 1)
			ans += c[i];
	}
	for(int i = 1; i <= n; ++i) 
		for(int j = i + 1; j <= n; ++j)
			if(c[i] > c[j])
				swap(c[i], c[j]), swap(p[i], p[j]);
	for(int i = 0; i <= n; ++i) {
		tmp = 0;
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		for(int j = n; j > 0; --j) {
			if(p[j] == 1 || cnt[p[j]] < i) {
				cnt[p[j]]++;
			}
			else {
				tmp += c[j];
				vis[j] = 1;
				cnt[1]++;
			}
		}
		for(int j = 1; j <= n; ++j) 
			if(cnt[1] <= i && p[j] != 1 && vis[j] == 0)
				tmp += c[j], cnt[1]++;
		if(cnt[1] > i)
			ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
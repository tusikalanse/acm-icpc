#include <bits/stdc++.h>
#define LL long long
using namespace std;

map< pair<int, int>, int> vis;
unordered_map<int, int> m1;
vector<int> v;
int a[1010], n;

bool judge(int x, int y) {
	if(vis.find(make_pair(x, y)) != vis.end())
		return 0;
	return vis[make_pair(x, y)] = 1;
}

int main() {
	v.clear();
	int mx = -1e9;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		m1[a[i]]++;
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + n + 1);
	LL ans = 2;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			if(!judge(a[i], a[j]))
				continue;
			v.clear();
			LL x = a[i], y = a[j], cnt = 2, z = x + y;
			m1[x]--;
			m1[y]--;
			while(z <= mx && m1[z]) {
				m1[z]--;
				v.push_back(z);
				cnt++;
				x = y;
				y = z;
				z = x + y;
			}
			for(int i = 0; i < v.size(); ++i)
				m1[v[i]]++;
			m1[a[i]]++;
			m1[a[j]]++;
			ans = max(ans, cnt);
		}
	printf("%lld\n", ans);
	return 0;
}
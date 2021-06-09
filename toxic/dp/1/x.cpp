#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int fa[N], r[N], n, m, q, k;
map<string, int> dict;
string s, t;

int find(int x) {
	if(x == fa[x])
		return x;
	int pre = fa[x];
	fa[x] = find(fa[x]);
	r[x] = r[x] ^ r[pre];
	return fa[x];
}

bool unite(int x, int y, int k) {
	int fx = find(x), fy = find(y);
	if(fx != fy) {
		fa[fx] = fy;
		r[fx] = r[x] ^ r[y] ^ k;
		return 1;
	}
	return r[x] ^ r[y] ^ r[fx] ^ r[fy] == k;
}

int judge(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy)
		return 3;
	if(r[x] ^ r[fx] != r[y] ^ r[fy])
		return 2;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i)	{
		cin >> s;
		dict[s] = i;
		fa[i] = i;
		r[i] = 0;
	}
	while(m--) {
		cin >> k >> s >> t;
		if(unite(dict[s], dict[t], k - 1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	while(q--) {
		cin >> s >> t;
		cout << judge(dict[s], dict[t]) << endl;
	}
	return 0;
}
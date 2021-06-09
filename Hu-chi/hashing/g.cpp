#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 1e9 + 7, seed = 65537, seed2 = 233;
map<LL, int> Hash, h2;
map< pair<int, int>, int > vis;
LL f[100010], h[100010];
map<int, int> cnt;

void init() {
	f[1] = h[1] = 1;
	for(int i = 2; i <= 100005; ++i) {
		f[i] = f[i - 1] * seed % mod;
		h[i] = h[i - 1] * seed2 % mod;
	}
}

LL P(LL n) {
	LL res = 1;
	for(int i = 2; i <= n; ++i)
		res = res * i % mod;
	return res;
}


int main() {
	init();
	int n, m, k, t;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		cnt.clear();
		while(k--) {
			scanf("%d", &t);
			cnt[t]++;
		}
		for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
			Hash[it->first] = (Hash[it->first] + (it->second) * f[i]) % mod;
			h2[it->first] = (h2[it->first] + (it->second) * h[i]) % mod;
		}
	}
	LL res = P(m - Hash.size());
	for(map<LL, int>::iterator it = Hash.begin(); it != Hash.end(); ++it) {
		vis[make_pair(it->second, h2[it->first])]++;
	}
	for(map<pair<int, int>, int>::iterator it = vis.begin(); it != vis.end(); ++it) {
		res = (res * P(it->second)) % mod;
	}
	printf("%lld\n", res);
	return 0;
}
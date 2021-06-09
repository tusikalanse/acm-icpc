			// cout << "type, cnt = " << temp.id << " " << cnt << endl;
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, a[N], c[N], t, d, cnt;

struct node {
	int cost, id;
	bool operator<(const node &rhs) const {
		if(cost == rhs.cost)
			return id < rhs.id;
		return cost < rhs.cost;
	}
}temp;

map<node, int> mp;


int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);	
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
		temp.cost = c[i];
		temp.id = i;
		mp[temp] = a[i];
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &t, &d);
		long long ans = 0;
		temp.cost = c[t], temp.id = t;
		if(mp.find(temp) != mp.end()) {
			cnt = min(mp[temp], d);
			d -= cnt;
			mp[temp] -= cnt;
			ans += 1LL * cnt * temp.cost;
			if(mp[temp] == 0)
				mp.erase(temp);
		}
		while(d > 0) {
			if(mp.empty()) break;
			temp = mp.begin()->first;
			cnt = min(mp[temp], d);
			d -= cnt;
			mp[temp] -= cnt;
			ans += 1LL * cnt * temp.cost;
			if(mp[temp] == 0)
				mp.erase(temp);
		};
		if(d != 0)
			ans = 0;
		printf("%lld\n", ans);
	}
	return 0;
}
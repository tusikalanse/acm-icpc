#include <bits/stdc++.h>
using namespace std;

int T, n, a, bef;
int ans1, ans2;
double m;
multiset<int> cnt;


int main() {
	scanf("%d", &T);
	while(T--) {
		bitset<10100> vis;
		scanf("%d", &n);
		cnt.clear();
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a);
			if(vis[a]) {
				vis[a] = 0;
				cnt.insert(a);
			}
			else
				vis[a] = 1;
		}
		auto it = cnt.begin();
		bef = *it;
		m = 10001;
		for(++it; it != cnt.end(); ++it) {
			if(double(*it) / bef < m) {
				m = double(*it) / bef;
				ans1 = bef;
				ans2 = *it;
			}
			bef = *it;
		}
		printf("%d %d %d %d\n", ans1, ans1, ans2, ans2);
	}
	return 0;
}
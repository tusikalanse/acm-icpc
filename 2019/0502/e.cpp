#include <bits/stdc++.h>
using namespace std;


multiset<int> s;
stack<int> t;
int T, n, ans, a, mx;

int main() {
	scanf("%d", &T);
	while(T--) {
		s.clear();
		scanf("%d", &n);
		scanf("%d", &a);
		mx = a;
		s.insert(a);
		ans = 0;
		for(int i = 2; i <= n; ++i) {
			scanf("%d", &a);
			if(a < mx) {
				auto p = s.lower_bound(a);
				for(auto it = s.begin(); it != p; ++it) {
					ans++;
					t.push(*it);
				}
				while(!t.empty()) {
					s.erase(s.find(t.top()));
					t.pop();
				}
				ans++;
			}
			else
				s.insert(a);
			mx = max(mx, a);
		}
		printf("%d\n", ans);
	}
	return 0;
}
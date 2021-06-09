#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

int T, n;
PII a[100010];

map<int, vector<int>> G;
set<int> s;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	scanf("%d", &T);
	while(T--) {
		s.clear();
		while(!q.empty()) q.pop();
		G.clear();
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].first, &a[i].second);
			G[a[i].first].push_back(a[i].second);
			s.insert(a[i].first);
		}
		sort(a, a + n);
		int ans = 0, l = 0;
		for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
			auto p = it, pp = ++it;
			--it;
			if(pp == s.end()) {
				l = max(l, *p);
				for(auto i : G[*p])
					q.push(i);
				while(!q.empty()) {
					while(!q.empty() && q.top() < l) {
						q.pop();
					}
					if(!q.empty()) {
						q.pop();
						l++;
						ans++;
					}
				}
				continue;
			}
			l = max(l, *it);
			for(auto i : G[*it])
				q.push(i);
			while(!q.empty() && l < *pp) {
				while(!q.empty() && q.top() < l) {
					q.pop();
				}
				if(!q.empty()) {
					q.pop();
					l++;
					ans++;
				}
			}	
		}
		printf("%d\n", ans);
	}
	return 0;
}
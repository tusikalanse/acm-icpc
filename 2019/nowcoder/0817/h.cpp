#include <bits/stdc++.h>
using namespace std;

int T, a, b;
vector<int> deg[10], cnt[10];

int main() {
	scanf("%d", &T);
	while(T--) {
		for(int i = 1; i <= 6; ++i) deg[i].clear(), cnt[i].clear();
		for(int i = 1; i <= 5; ++i) {
			scanf("%d%d", &a, &b);
			deg[a].push_back(b);
			deg[b].push_back(a);
		}
		for(int i = 1; i <= 6; ++i)
			cnt[deg[i].size()].push_back(i);
		if(cnt[4].size() == 1) {
			puts("2,2-dimethylbutane");
		}
		else if(cnt[1].size() == 4) {
			puts("2,3-dimethylbutane");
		}
		else if(cnt[1].size() == 2) {
			puts("n-hexane");
		}
		else {
			int tot = 0;
			int f = cnt[3][0];
			for(auto i : deg[f])
				tot += deg[i].size();
			if(tot == 4) {
				puts("2-methylpentane");
			}
			else {
				assert(tot == 5);
				puts("3-methylpentane");
			}
		}
	}
	return 0;
}
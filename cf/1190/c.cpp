#include <bits/stdc++.h>
using namespace std;

vector<int> pos[2];
int n, k;
char s[100010];

int main() {
	scanf("%d%d%s", &n, &k, s);
	for(int i = 0; i < n; ++i) {
		pos[s[i] - '0'].push_back(i);
	}
	if(pos[0].empty() || pos[1].empty()) {
		puts("tokitsukaze");
		return 0;
	}
	bool flag = false;
	for(int l = 0, r = k - 1; r < n; ++l, ++r) {
		vector<int> tmp[2];
		for(int i = 0; i < 2; ++i) {
			if(pos[i].front() < l || pos[i].front() > r)
				tmp[i].push_back(pos[i].front());
			if(pos[i].back() < l || pos[i].back() > r)
				tmp[i].push_back(pos[i].back());
			vector<int>::iterator it;
			it = lower_bound(pos[i].begin(), pos[i].end(), l);
			if(it != pos[i].begin()) 
				tmp[i].push_back(*--it);
			it = upper_bound(pos[i].begin(), pos[i].end(), r);
			if(it != pos[i].end())
				tmp[i].push_back(*it);
			sort(tmp[i].begin(), tmp[i].end());
		}
		if(tmp[0].empty() || tmp[1].empty()) {
			puts("tokitsukaze");
			return 0;
		}
		flag |= tmp[0].back() - tmp[0].front() >= k || tmp[1].back() - tmp[1].front() >= k;
	}
	puts(flag ? "once again" : "quailty");
	return 0;
}
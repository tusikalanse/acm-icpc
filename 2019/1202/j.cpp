#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int T, n, c;
int cnt[N];
vector<int> gao, ans[2];

bool judge(int s, int tot) {
	int page = 1 + (tot - 1) / s;
	return page >= page * s - tot;
}

int f(int pagesize) {
	int res = 0;
	for (auto i: gao) 
		res += 1 + (i - 1) / pagesize;
	return res;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(int) * (n + 8));
		gao.clear(); ans[0].clear(); ans[1].clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &c);
			cnt[c]++;
		}
		for (int i = 1; i <= n; ++i) {
			if (cnt[i]) 
				gao.push_back(cnt[i]);
			ans[0].push_back(i);
		}
		int out = 1e9;
		for (int i = 0; i < gao.size(); ++i) {
			ans[1 ^ (i & 1)].clear();
			for (auto num: ans[i & 1])
				if (judge(num, gao[i]))
					ans[1 ^ (i & 1)].push_back(num);
			if (i + 1 == gao.size()) {
				for (auto num: ans[1 ^ (i & 1)]) {
					out = min(out, f(num));
				}
			}
		}
		printf("%d\n", out);
	}
	return 0;
}
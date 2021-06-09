#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, k, l;
int cnt[30], len[N];
char ans[N][N], s[N * N];

char getnext() {
	static int now = 0;
	while (cnt[now] == 0) now++;
	cnt[now]--;
	return now + 'a';
}

vector<int> togo[2];

int main() {
	scanf("%d%d%d%s", &n, &l, &k, s);
	for (int i = 0; i < n * l; ++i)
		cnt[s[i] - 'a']++;
	for (int i = 1; i < k; ++i) togo[0].push_back(i);
	for (int i = 0; i < l; ++i) {
		for (auto j: togo[i & 1]) {
			ans[j][i] = getnext();
			len[j] = i + 1;
		}
		ans[k][i] = getnext();
		togo[1 ^ (i & 1)].clear();
		for (auto j: togo[i & 1])
			if (ans[j][i] == ans[k][i])
				togo[1 ^ (i & 1)].push_back(j);
	}
	len[k] = l;
	for (int i = 1; i <= n; ++i) {
		for (int j = len[i]; j < l; ++j)
			ans[i][j] = getnext();
		puts(ans[i]);
	}
	return 0;
}
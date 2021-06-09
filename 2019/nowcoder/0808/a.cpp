#include <bits/stdc++.h>
using namespace std;

int T, n;
char s[210];
vector<pair<int, int>> ans;

bool min_represent(int l, int r) {
	static char ss[210];
	for(int i = l; i <= r; ++i) {
		ss[i - l] = s[i];
	}
	int i = 0, j = 1, k = 0, len = r - l + 1;
	while(i < len && j < len && k < len) {
		int t = ss[(i+k) % len] - ss[(j+k) % len];
		if(t == 0)
			++k;
		else {
			if(t > 0)
				i += k + 1;
			else
				j += k + 1;
			if(i == j)
				++j;
			k = 0;
		}
	}
	return min(i, j) == 0;
}

void judge() {
	int l = 0, r;
	while(l < n) {
		for(r = n - 1; r >= l; --r) {
			if(min_represent(l, r)) {
				ans.push_back({l, r});
				break;
			}
		}
		l = r + 1;
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		ans.clear();
		scanf("%s", s);
		n = strlen(s);
		judge();
		for(int i = 0; i < ans.size(); ++i) {
			for(int j = ans[i].first; j <= ans[i].second; ++j)
				putchar(s[j]);
			putchar(" \n"[i + 1 == ans.size()]);
		}
	}
	return 0;
}
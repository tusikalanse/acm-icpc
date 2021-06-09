#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m, ans = -1;
char a[N], b[N];

vector<int> v[26];
int tp[26];

int main() {
	scanf("%d%d%s%s", &n, &m, a, b);
	for(int i = 0; i < n; ++i) {
		v[a[i] - 'a'].push_back(i);
	}
	int i, j;
	for(i = 0, j = 0; j < m; ++j) {
		for(int p = b[j] - 'a' + 1; p < 26; ++p) {
			if(tp[p] != v[p].size()) {
				ans = max(ans, n - v[p][tp[p]] + j);
			}
		}
		int p = b[j] - 'a';
		if(tp[p] == v[p].size())
			break;
		i = v[p][tp[p]];
		for(int pp = 0; pp < 26; ++pp) {
			while(tp[pp] != v[pp].size() && v[pp][tp[pp]] <= i)
				tp[pp]++;
		}
	}
	if(j == m && i != n - 1) {
		ans = max(ans, m + n - i - 1);
	}
	printf("%d\n", ans);
	return 0;
}
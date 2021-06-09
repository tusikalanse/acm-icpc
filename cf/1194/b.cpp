#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int T, n, m;

vector<char> mp[N];

char s[N];
int row[N], col[N], l;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) {
			scanf("%s", s);
			mp[i].resize(m);
			for(int j = 0; j < m; ++j) {
				mp[i][j] = s[j];
			}
			row[i] = 0;
		}
		for(int j = 0; j < m; ++j) {
			col[j] = 0;
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(mp[i][j] == '*') {
					row[i]++;
					col[j]++;
				}
			}
		}
		int ans = n * m, tmp;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(mp[i][j] == '.')
					tmp = m - row[i] + n - col[j] - 1;
				else
					tmp = m - row[i] + n - col[j];
				ans = min(ans, tmp);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

char mp[110][110];
int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};


int main() {
	int n, m;
	int flag = 1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", &mp[i][1]);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if((mp[i][j] <= '8' && mp[i][j] >= '1') || mp[i][j] == '.') {
				int cnt = 0;
				for(int k = 0; k < 8; ++k) {
					int fx = i + dir[k][0], fy = j + dir[k][1];
					if(fx > 0 && fx <= n && fy > 0 && fy <= m)
						cnt += (mp[fx][fy] == '*');
				}
				if(mp[i][j] == '.') {
					if(cnt != 0) {
						flag = 0;
						goto out;
					}
				}
				else {
					if(cnt != mp[i][j] - '0') {
						flag = 0;
						goto out;
					}
				}
			}
		}
	}
	out:;
	puts(flag?"YES":"NO");

	return 0;
}
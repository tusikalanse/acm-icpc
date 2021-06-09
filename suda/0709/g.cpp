#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
char mp[MAXN][MAXN];
int s[MAXN][MAXN];

int main() {
	pair<int, int> u;
	int n, m, k, x1, x2, y1, y2, stp;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%s", &mp[i][1]);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	queue< pair<int, int> > bfs;
	memset(s, -1, sizeof(s));
	bfs.push(make_pair(x1, y1));
	s[x1][y1] = 0;
	while(!bfs.empty()) {
		u = bfs.front();
		stp = s[u.first][u.second];
		bfs.pop();
		if(u.first == x2 && u.second == y2)
			break;
		for(int i = 1; i <= k && u.first + i <= n; i++) {
			if(s[u.first + i][u.second] != -1)
				continue;
			if(mp[u.first + i][u.second] == '#')
				break;
			s[u.first + i][u.second] = stp + 1;
			if(u.first + i == x2 && u.second == y2) {
				printf("%d\n", stp + 1);
				return 0;
			}
			bfs.push(make_pair(u.first + i, u.second));
		}
		for(int i = 1; i <= k && u.first - i > 0; i++) {
			if(s[u.first - i][u.second] != -1)
				continue;
			if(mp[u.first - i][u.second] == '#')
				break;
			s[u.first - i][u.second] = stp + 1;
			if(u.first - i == x2 && u.second == y2) {
				printf("%d\n", stp + 1);
				return 0;
			}
			bfs.push(make_pair(u.first - i, u.second));
		}
		for(int i = 1; i <= k && u.second + i <= m; i++) {
			if(s[u.first][u.second + i] != -1)
				continue;
			if(mp[u.first][u.second + i] == '#')
				break;
			s[u.first][u.second + i] = stp + 1;
			if(u.first == x2 && u.second + i == y2) {
				printf("%d\n", stp + 1);
				return 0;
			}
			bfs.push(make_pair(u.first, u.second + i));
		}
		for(int i = 1; i <= k && u.second - i > 0; i++) {
			if(s[u.first][u.second - i] != -1)
				continue;
			if(mp[u.first][u.second - i] == '#')
				break;
			s[u.first][u.second - i] = stp + 1;
			if(u.first == x2 && u.second - i == y2) {
				printf("%d\n", stp + 1);
				return 0;
			}
			bfs.push(make_pair(u.first, u.second - i));
		}
	}
	printf("%d\n", s[x2][y2]);
	return 0;
}
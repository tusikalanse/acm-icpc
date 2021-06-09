#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

vector<pair<int, int>> G[N][N];
char s[N * 4][N * 6];
int dis[N][N];
int cas, r, c;
pair<int, int> S, T;

bool judge(int i, int j, char ch) {
	int x = i * 4, y = 6 * j - 1;
	if (j % 2 == 1)
		x--;
	else
		x++;
	return s[x][y] == ch;
}

void bfs() {
	queue<pair<int, int>> que;
	que.push(S);
	dis[S.first][S.second] = 1;
	while (!que.empty()) {
		pair<int, int> tmp = que.front();
		que.pop();
		for (auto s: G[tmp.first][tmp.second]) {
			if (dis[s.first][s.second] == 100000000) {
				dis[s.first][s.second] = dis[tmp.first][tmp.second] + 1;
				que.push(s);
			}
		}
	}
}

int main() {
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			dis[i][j] = 100000000;
		}
	}
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d%d", &r, &c); getchar();
		for (int i = 1; i <= 4 * r + 3; ++i) { 
			fgets(s[i] + 1, 6 * c + 10, stdin);
			if (i % 4 == 1) {
				for (int j = 5, col = 1; j <= 6 * c + 3; j += 12, col += 2) {
					if (s[i][j] == ' ') {
						int r1 = (i / 4), r2 = r1 + 1;
						G[r1][col].emplace_back(r2, col);
						G[r2][col].emplace_back(r1, col);
					}
				}
			}
			else if (i % 4 == 2) {
				for (int j1 = 2, j2 = 8, col = 1; j2 <= 6 * c + 3; j1 += 12, j2 += 12, col += 2) {
					if (s[i][j1] == ' ') {
						int r1 = i / 4 + 1, r2 = r1 - 1;
						G[r1][col].emplace_back(r2, col - 1);
						G[r2][col - 1].emplace_back(r1, col);
					}
					if (s[i][j2] == ' ') {
						int r1 = i / 4 + 1, r2 = r1 - 1;
						G[r1][col].emplace_back(r2, col + 1);
						G[r2][col + 1].emplace_back(r1, col);
					}
				}
			}
			else if (i % 4 == 3) {
				for (int j = 11, col = 2; j <= 6 * c + 3; j += 12, col += 2) {
					if (s[i][j] == ' ') {
						int r1 = i / 4, r2 = r1 + 1;
						G[r1][col].emplace_back(r2, col);
						G[r2][col].emplace_back(r1, col);
					}
				}
			}
			else {
				for (int j1 = 2, j2 = 8, col = 1; j2 <= 6 * c + 3; j1 += 12, j2 += 12, col += 2) {
					if (s[i][j1] == ' ') {
						int r1 = i / 4, r2 = r1;
						G[r1][col].emplace_back(r2, col - 1);
						G[r2][col - 1].emplace_back(r1, col);
					}
					if (s[i][j2] == ' ') {
						int r1 = i / 4, r2 = r1;
						G[r1][col].emplace_back(r2, col + 1);
						G[r2][col + 1].emplace_back(r1, col);
					}
				}
			}
		}
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				if (judge(i, j, 'S'))
					S = make_pair(i, j);
				else if (judge(i, j, 'T'))
					T = make_pair(i, j);
			}
		}
		bfs();
		if (dis[T.first][T.second] == 100000000) 
			puts("-1");
		else 
			printf("%d\n", dis[T.first][T.second]);
		for (int i = 1; i <= r; ++i) 
			for (int j = 1; j <= c; ++j) {
				dis[i][j] = 100000000;
				G[i][j].clear();
			}
	}
	return 0;
}
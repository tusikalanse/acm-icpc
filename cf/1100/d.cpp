#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;

pair<int, int> pos[667];
int vis[N][N], mx, my, k, x, y;

void move(int dx, int dy) {
	if(vis[mx + dx][my + dy])
		dx = 0;
	int fx = mx + dx, fy = my + dy;
	cout << fx << " " << fy << endl;
	cin >> k >> x >> y;
	if(k == -1)
		exit(0);
	vis[pos[k].first][pos[k].second] = 0;
	pos[k] = make_pair(x, y);
	vis[pos[k].first][pos[k].second] = k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> mx >> my;
	for(int i = 1; i <= 666; ++i) {
		cin >> x >> y;
		vis[x][y] = i;
		pos[i] = make_pair(x, y);
	}
	while(mx < 500) move(1, 0), ++mx;
	while(mx > 500) move(-1, 0), --mx;
	while(my < 500) move(0, 1), ++my;
	while(my > 500) move(0, -1), --my;
	int ul = 0, dl = 0, ur = 0, dr = 0;
	for(int i = 1; i <= 666; ++i) {
		if(pos[i].first < 500 || pos[i].second < 500)
			dl++;
		if(pos[i].first < 500 || pos[i].second > 500)
			ul++;		
		if(pos[i].first > 500 || pos[i].second < 500)
			dr++;		
		if(pos[i].first > 500 || pos[i].second > 500)
			ur++;
	}
	if(ul >= 500) while(1) move(-1, 1), --mx, ++my;
	if(ur >= 500) while(1) move(1, 1), ++mx, ++my;
	if(dl >= 500) while(1) move(-1, -1), --mx, --my;
	if(dr >= 500) while(1) move(1, -1), ++mx, --my;
	return 0;
}	
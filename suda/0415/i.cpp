#include <bits/stdc++.h>
using namespace std;

map<int, int> tme[100010];
map<int, long long> col[100010];
int c[100010], head[100010], pnt[100010*2], nxt[100010*2], cnt = 0;
long long ans[100010];

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs(int rt, int fa) {
	col[rt].clear();
	tme[rt].clear();
	col[rt][1] = c[rt];
	tme[rt][c[rt]] = 1;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		if(pnt[i] == fa) continue;
		dfs(pnt[i], rt);
		if(tme[rt].size() < tme[pnt[i]].size()) {
			swap(col[rt], col[pnt[i]]);
			swap(tme[rt], tme[pnt[i]]);
		}
		for(map<int, int>::iterator it = tme[pnt[i]].begin(); it != tme[pnt[i]].end(); it++) {
			int x = it->first, y = it->second;
			if(tme[rt].count(x)) {
				col[rt][tme[rt][x]] -= x;
				tme[rt][x] += y;
				col[rt][tme[rt][x]] += x;				
			}
			else {
				tme[rt][x] = y;
				col[rt][tme[rt][x]] += x;	
			}
		}
	}
	ans[rt] = ((col[rt].rbegin()) -> second);
}

int main() {
	int n, x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		head[i] = -1;
		scanf("%d", &c[i]);
	}
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, -1);
	for(int i = 1; i <= n; i++) {
		printf("%lld%c", ans[i], (i == n) ? '\n' : ' ');
	}
	return 0;
}
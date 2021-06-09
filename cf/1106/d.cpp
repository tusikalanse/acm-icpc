#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
const int N = 1e5 + 10;

int head[N], vis[N], pnt[N << 1], nxt[N << 1], cnt, n, m, x, y;

vector<int> ans;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	pq.push(1);
	while(!pq.empty()) {
		int t = pq.top();
		pq.pop();
		if(vis[t]) continue;
		vis[t] = 1;
		ans.push_back(t);
		for(int i = head[t]; ~i; i = nxt[i]) {
			int j = pnt[i];
			if(vis[j]) continue;
			pq.push(j);
		}
	}
	for(int i = 0; i < ans.size(); ++i)
		printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
	return 0;
}
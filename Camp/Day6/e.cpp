#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> G[N << 2], ans;
int deg[N << 2], pos[N], id[N << 2], a[N], n;

void add(int x, int y) {
	G[x].push_back(y);
	++deg[y];
}

void build(int rt, int l, int r) {
	id[rt] = -1;
	if(l == r) {
		pos[l] = rt;
		id[rt] = l;
		return;
	}
	int mid = l + r >> 1;
	add(rt << 1, rt);
	add(rt << 1 | 1, rt);
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void Add(int rt, int l, int r, int L, int R, int pnt) {
	if(L <= l && r <= R) {
		add(rt, pos[pnt]);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid)
		Add(rt << 1, l, mid, L, R, pnt);
	if(mid < R)
		Add(rt << 1 | 1, mid + 1, r, L, R, pnt);
}

void topo() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 0; i < n; ++i) 
		if(!deg[pos[i]])
			pq.push(make_pair(a[i], pos[i]));
	while(!pq.empty()) {
		pair<int, int> u = pq.top();
		pq.pop();
		if(u.first != -1)
			ans.push_back(u.first);
		for(auto &it: G[u.second])
			if(--deg[it] == 0)
				pq.push(make_pair(~id[it] ? a[id[it]] : -1, it));
	}
	for(int i = 0; i < ans.size(); ++i) {
		printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
	}
}

int main() {
	scanf("%d", &n);
	build(1, 0, n - 1);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		int tmp = a[i] % n;
		if(tmp == i) continue;
		if(tmp < i)
			Add(1, 0, n - 1, tmp, i - 1, i);
		else {
			Add(1, 0, n - 1, tmp, n - 1, i);
			if(i)
				Add(1, 0, n - 1, 0, i - 1, i);
		}
	}
	topo();
	return 0;
}
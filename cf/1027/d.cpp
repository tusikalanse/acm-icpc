#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], c[N], fd, n, hd;

int head[N], nxt[N], pnt[N], vis[N], cnt, ans, tmp;
int head2[N], nxt2[N], pnt2[N], vis2[N], cnt2;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void add2(int x, int y) {
	pnt2[cnt2] = y;
	nxt2[cnt2] = head2[x];
	head2[x] = cnt2++;
}

void huan(int rt) {
	if(hd) return;
	vis2[rt] = 1;
	for(int i = head[rt]; ~i && !hd; i = nxt[i]) {
		int j = pnt[i];
		if(vis2[j]) {
			hd = 1;
			return;
		}
		else {
			vis2[j] = 1;
			huan(j);
			if(!hd)
				vis2[j] = 0;
		}
	}
}

void dfs2(int rt) {
	if(vis2[rt] == 1) {
		tmp = min(c[rt], tmp);
	}
	vis[rt] = 2;
	for(int i = head2[rt]; ~i; i = nxt2[i]) {
		int j = pnt2[i];
		if(vis[j] == 1) {
			if(rt != j)	dfs2(j);
		}
		else if(vis[j] == 0) 
			dfs2(j);
	}
}

void dfs(int rt) {
	if(fd) 
		return;
	for(int i = head[rt]; ~i && !fd; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] == 2)
			continue;
		if(vis[j]) {
			fd = 1;
			tmp = 1e9;
			hd = 0;
			huan(j);
			dfs2(j);
			ans += tmp;
			break;
		}
		else {
			vis[j] = 1;
			dfs(j);
			if(!fd)
				vis[j] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	memset(head, -1, sizeof(head));
	memset(head2, -1, sizeof(head2));
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &c[i]);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		add(i, a[i]);
		add2(a[i], i);
	}
	for(int i = 1; i <= n; ++i)
		if(vis[i] == 0) {
			fd = 0;
			vis[i] = 1;
			dfs(i);
		}
	printf("%d\n", ans);
	return 0;
}
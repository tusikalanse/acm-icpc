#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[1010][1010];
int rnk[2010];
int head[2010], nxt[1000010], pnt[1000010], cnt, num, now, bef, vv;
int in[2010], fa[2010];

void add(int x, int y) {
	nxt[cnt] = head[x];
	pnt[cnt] = y;
	head[x] = cnt++;
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy)
		fa[fx] = fy;
}


int main() {
	bool f = true;
	scanf("%d%d", &n, &m);
	iota(fa + 1, fa + n + m + 1, 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", &s[i][1]);
		for(int j = 1; j <= m; ++j) {
			if(s[i][j] == '=') {
				unite(n + j, i);
			}
			else
				f = false;
		}
	}
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i][j] == '<') {
				add(find(i), find(n + j));
				in[find(n + j)]++;
			}
			if(s[i][j] == '>') {
				add(find(n + j), find(i));
				in[find(i)]++;
			}
		}
	}
	for(int i = 1; i <= n + m; ++i)
		num += find(i) == i;
	if(num == 1) {
		if(f == false)
			puts("No");
		else {
			puts("Yes");
			for(int i = 1; i <= n + m; ++i)
				printf("%d%c", 1, " \n"[(i == n) | (i == n + m)]);
		}
		return 0;
	}
	queue<int> que;
	stack<int> stk;
	for(int i = 1; i <= n + m; ++i) {
		if(find(i) == i && in[i] == 0)
			que.push(i);
	}
	cnt = 1;
	while(!que.empty()) {
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			stk.push(u);
			rnk[u] = cnt;
			++now;
		}
		cnt += 1;
		while(!stk.empty()) {
			int u = stk.top();
			stk.pop();
			for(int i = head[u]; ~i; i = nxt[i]) {
				int j = pnt[i];
				if(--in[j] == 0) 
					que.push(j);
			}
		}
	}
	if(now != num) {
		puts("No");
	}
	else {
		puts("Yes");
		for(int i = 1; i <= n + m; ++i)
			printf("%d%c", rnk[find(i)], " \n"[(i == n) | (i == n + m)]);
	}
	return 0;
}
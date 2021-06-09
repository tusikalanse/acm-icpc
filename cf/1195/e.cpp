#include <bits/stdc++.h>
using namespace std;

int n, m, h[3010][3010], g, x, y, z, head, tail, a, b, id;
long long ans;

struct node {
	int id, val;
	node() {}
	node(int _val, int _id) : id(_id), val(_val) {}
}que[3010];

int main() {
	scanf("%d%d%d%d%d%d%d%d", &n, &m, &a, &b, &g, &x, &y, &z);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			h[i][j] = g;
			g = (1LL * g * x + y) % z;
		}
	}
	for(int i = 0; i < n; ++i) {
		head = tail = 0;
		id = 0;
		for(int j = 0; j + b - 1 < m; ++j) {
			while(head < tail && que[head].id < j) head++;
			while(id <= j + b - 1) {
				while(head < tail && que[tail - 1].val >= h[i][id]) tail--;
				que[tail++] = node(h[i][id], id);
				id++;
			}
			h[i][j] = que[head].val;
		}
	}
	for(int i = 0; i + b - 1 < m; ++i) {
		head = tail = 0;
		id = 0;
		for(int j = 0; j + a - 1 < n; ++j) {
			while(head < tail && que[head].id < j) head++;
			while(id <= j + a - 1) {
				while(head < tail && que[tail - 1].val >= h[id][i]) tail--;
				que[tail++] = node(h[id][i], id);
				id++;
			}
			h[j][i] = que[head].val;
		}
	}
	for(int i = 0; i + a - 1 < n; ++i) {
		for(int j = 0; j + b - 1 < m; ++j)
			ans += h[i][j];
	}
	printf("%lld\n", ans);
	return 0;
}
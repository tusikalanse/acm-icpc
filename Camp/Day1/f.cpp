#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

typedef long long LL;

int n, m, k, x, y, z, h[N];
LL height, dis[N], v[N];
int head[N], pnt[N << 1], nxt[N << 1], val[N << 1], cnt;

void add(int x, int y, int z) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	val[cnt] = z;
	head[x] = cnt++;
}

struct node {
	int x;
	LL d;
	bool operator<(const node &rhs) const {
		return d > rhs.d;
	}
};

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	height = h[1] + k;
	for(int i = 1; i <= n; ++i) {
		if(h[i] > height)
			v[i] = 1LL * (h[i] - height) * (h[i] - height);
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	priority_queue<node> bfs;
	bfs.push({1, 0});
	while(!bfs.empty()) {
		node u = bfs.top();
		bfs.pop();
		if(u.x == n)
			break;
		if(u.d > dis[u.x]) continue;
		for(int i = head[u.x]; ~i; i = nxt[i]) {
			int j = pnt[i];
			LL ddd = u.d + val[i] + v[j];
			if(ddd < dis[j]) {
				dis[j] = ddd;
				bfs.push({j, ddd});
			}
		}
	}
	printf("%lld\n", dis[n]);
	return 0;
}
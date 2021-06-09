#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int pnt[N << 1], head[N], nxt[N << 1], cnt;
int deg[N], vis[N], valid[N];

int T, n, m, k, a, b, ans;
vector<int> vec;
double mx;

void init() {
	vec.clear();
	cnt = 0;
	ans = 0;
	mx = 0;
	memset(vis, 0, sizeof(vis));
	memset(valid, 0, sizeof(valid));
	memset(head, -1, sizeof(head));
	memset(deg, 0, sizeof(deg));
}

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs(int rt) {
	vis[rt] = -1;
	ans++;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(valid[j]) vec.push_back(j);
		if(vis[j] || valid[j]) continue;
		dfs(j);
	}
}

int dfs(int rt, vector<int> &v) {
	v.push_back(rt);
	vis[rt] = 1;
	int ans = 1;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(valid[j] || vis[j]) continue;
		ans += dfs(j, v);
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d", &a, &b);
			add(a, b);
			add(b, a);
			deg[a]++; deg[b]++;
		}
		for(int i = 1; i <= k; ++i) {
			scanf("%d", &a);
			valid[a] = 1;
		}
		dfs(1);
		for(auto rt: vec) {
			double tot = 0;
			for(int i = head[rt]; ~i; i = nxt[i]) {
				int j = pnt[i];
				if(valid[j]) continue;
				if(vis[j] == -1) continue;
				if(vis[j]) {tot += vis[j]; continue;}
				vector<int> v;
				int t = dfs(j, v);
				tot += t;
				for(auto k: v)
					vis[k] = t;
			}
			mx = max(mx, tot / deg[rt]);
		}
		printf("%.15f\n", ans + mx);
	}
	return 0;
}
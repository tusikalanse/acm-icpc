#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long answer;
int v[N];
int T, n, x, y;
vector<int> G[N];
int mx[N][3], p[N][3], ans[N][2];
int mxson[N][2], ps[N][2];

void dfs(int rt, int fa) {
	mx[rt][0] = 1; mx[rt][1] = -1e9; mx[rt][2] = -1e9;
	p[rt][0] = rt; p[rt][1] = -1; mx[rt][2] = -1;
	ans[rt][0] = 1;
	mxson[rt][0] = mxson[rt][1] = -1e9;
	ps[rt][0] = ps[rt][1] = -1;
	for(int v: G[rt]) {
		if(v == fa) continue;
		dfs(v, rt);
		if(mx[rt][2] < mx[v][0] + 1) {
			mx[rt][2] = mx[v][0] + 1;
			p[rt][2] = v;
		}
		if(mx[rt][2] > mx[rt][1]) {
			swap(mx[rt][2], mx[rt][1]);
			swap(p[rt][2], p[rt][1]);
		}
		if(mx[rt][1] > mx[rt][0]) {
			swap(mx[rt][1], mx[rt][0]);
			swap(p[rt][1], p[rt][0]);
		}
		if(ans[v][0] > mxson[rt][1]) {
			mxson[rt][1] = ans[v][0];
			ps[rt][1] = v;
		}
		if(mxson[rt][1] > mxson[rt][0]) {
			swap(mxson[rt][1], mxson[rt][0]);
			swap(ps[rt][1], ps[rt][0]);
		}
		ans[rt][0] = max(ans[rt][0], ans[v][0]);
	}
	ans[rt][0] = max(mx[rt][0] + mx[rt][1] - 1, ans[rt][0]);
}

void dfs2(int rt, int fa, int tmp, int len) {
	ans[rt][1] = tmp;
	for(int v: G[rt]) {
		if(v == fa) continue;
		int new_tmp = tmp;
		int new_len = len + 1;
		if(p[rt][0] != v) {
			new_len = max(new_len, mx[rt][0]);
		}
		if(p[rt][1] != v) {
			new_len = max(new_len, mx[rt][1]);
		}
		vector<int> vv;
		vv.push_back(len + 1);
		if(p[rt][0] != v)
			vv.push_back(mx[rt][0]);
		if(p[rt][1] != v)
			vv.push_back(mx[rt][1]);
		if(p[rt][2] != v)
			vv.push_back(mx[rt][2]);
		sort(vv.begin(), vv.end(), greater<int>());
		new_tmp = max(new_tmp, vv[0] + vv[1] - 1);
		if(ps[rt][0] != v)
			new_tmp = max(new_tmp, mxson[rt][0]);
		if(ps[rt][1] != v)
			new_tmp = max(new_tmp, mxson[rt][1]);
		dfs2(v, rt, new_tmp, new_len);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		answer = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1, 0);
		dfs2(1, 0, 0, 0);
		memset(v, 0, sizeof(int) * (n + 3));
		for(int i = 1; i <= n; ++i) {
			int a = ans[i][0], b = ans[i][1];
			v[a] = max(v[a], b);
			v[b] = max(v[b], a);
		}
		for(int i = n; i; --i)
			v[i] = max(v[i], v[i + 1]);
		for(int i = 1; i <= n; ++i) {
			answer += v[i];
		}
		printf("%lld\n", answer);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];

int a[N], b[N], T, n;

long long mxa[N][2], mnb[N][2], ans;
int posmxa[N][2], posmnb[N][2], f[N], x, y, root;

void dfs(int rt, int fa) {
	mxa[rt][0] = mxa[rt][1] = 1e18;
	mnb[rt][0] = mnb[rt][1] = -1e18;
	posmxa[rt][0] = posmxa[rt][1] = -1;
	posmnb[rt][0] = posmnb[rt][1] = -1;
	f[rt] = fa;
	for(auto j : G[rt]) {
		if(j == fa) continue;
		dfs(j, rt);
		if(mnb[j][0] + a[rt] - b[rt] < mxa[rt][1]) {
			mxa[rt][1] = mnb[j][0] + a[rt] - b[rt];
			posmxa[rt][1] = j;
		}
		if(mxa[rt][1] < mxa[rt][0]) {
			swap(mxa[rt][1], mxa[rt][0]);
			swap(posmxa[rt][1], posmxa[rt][0]);
		}
		if(mxa[j][0] + a[rt] - b[rt] > mnb[rt][1]) {
			mnb[rt][1] = mxa[j][0] + a[rt] - b[rt];
			posmnb[rt][1] = j;
		}
		if(mnb[rt][1] > mnb[rt][0]) {
			swap(mnb[rt][1], mnb[rt][0]);
			swap(posmnb[rt][1], posmnb[rt][0]);
		}
	}
	if(posmxa[rt][0] == -1) {
		mxa[rt][0] = mnb[rt][0] = a[rt] - b[rt];
	}
	// printf("mx[%d][0], mx[%d][1], px[%d][0], px[%d][1] = %lld, %lld, %d, %d\n", rt, rt, rt, rt, mxa[rt][0], mxa[rt][1], posmxa[rt][0], posmxa[rt][1]);
	// printf("mn[%d][0], mn[%d][1], pn[%d][0], pn[%d][1] = %lld, %lld, %d, %d\n", rt, rt, rt, rt, mnb[rt][0], mnb[rt][1], posmnb[rt][0], posmnb[rt][1]);
}

void dfs2(int rt, int fa) {
	if(fa != 0) {
		long long val, tmp = fa;
		if(posmnb[fa][0] == rt) {
			val = mnb[fa][1] + a[rt] - b[rt];
		}
		else {
			val = mnb[fa][0] + a[rt] - b[rt];
		}
		if(val < mxa[rt][1]) {
			mxa[rt][1] = val;
			posmxa[rt][1] = tmp;
		}
		if(mxa[rt][1] < mxa[rt][0]) {
			swap(mxa[rt][1], mxa[rt][0]);
			swap(posmxa[rt][1], posmxa[rt][0]);
		}
		if(posmxa[fa][0] == rt) {
			val = mxa[fa][1] + a[rt] - b[rt];
		}
		else {
			val = mxa[fa][0] + a[rt] - b[rt];
		}
		if(val > mnb[rt][1]) {
			mnb[rt][1] = val;
			posmnb[rt][1] = tmp;
		}
		if(mnb[rt][1] > mnb[rt][0]) {
			swap(mnb[rt][1], mnb[rt][0]);
			swap(posmnb[rt][1], posmnb[rt][0]);
		}
		// printf("mx[%d][0], mx[%d][1], px[%d][0], px[%d][1] = %lld, %lld, %d, %d\n", rt, rt, rt, rt, mxa[rt][0], mxa[rt][1], posmxa[rt][0], posmxa[rt][1]);
		// printf("mn[%d][0], mn[%d][1], pn[%d][0], pn[%d][1] = %lld, %lld, %d, %d\n", rt, rt, rt, rt, mnb[rt][0], mnb[rt][1], posmnb[rt][0], posmnb[rt][1]);
	}
	if(posmxa[rt][0] == -1) {
		swap(mxa[rt][0], mxa[rt][1]);
		swap(posmxa[rt][1], posmxa[rt][0]);
	}
	ans = max(ans, mxa[rt][0]);
	for(auto j : G[rt]) {
		if(j == fa) continue;
		dfs2(j, rt);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = -1e18;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			G[i].clear();
		}
		for(int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if(n <= 2) {
			ans = 0;
			for(int i = 1; i <= n; ++i)
				ans += a[i] - b[i];
			printf("%lld\n", ans);
			continue;
		}
		for(int i = 1; i <= n; ++i) {
			if(G[i].size() >= 2)
				root = i;
		}
		dfs(root, 0);
		dfs2(root, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
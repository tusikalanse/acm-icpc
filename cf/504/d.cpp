#include <bits/stdc++.h>
using namespace std;

bool flag = 1;
int n, q, zero, mx, cnt, fi = 0;
int a[200010], l[200010], r[200010];
vector<int> pos[200010];

bool vis[200010 << 2];

void pushup(int rt) {
	vis[rt] = vis[rt << 1] | vis[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	vis[rt] = 0;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos) {
	if(l == r) {
		vis[rt] = 1;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos);
	else
		update(rt << 1 | 1, mid + 1, r, pos);
	pushup(rt);
}

bool query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return vis[rt];
	int mid = l + r >> 1;
	bool ans = 0;
	if(mid >= L)
		ans |= query(rt << 1, l, mid, L, R);
	if(mid < R)
		ans |= query(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

int main() {
	mx = zero = 0;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		l[i] = 0;
		r[i] = n + 1;
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		zero += (a[i] == 0);
		mx = max(mx, a[i]);
		if(a[i]) {
			if(l[a[i]] == 0)
				l[a[i]] = i;
			r[a[i]] = i;
			pos[a[i]].push_back(i);
		}
	}
	if((mx < q && zero == 0)) 
		flag = 0;
	else {
		build(1, 1, n);
		for(int i = 1; i <= q; ++i) if(l[i]) {
			if(query(1, 1, n, l[i], r[i])) {
				flag = 0;
				goto out;
			}
			for(int j = 0; j < pos[i].size(); ++j)
				update(1, 1, n, pos[i][j]);
		}
		if(mx < q)
		for(int i = 1; i <= n; ++i) if(a[i] == 0) {
			a[i] = q;
			break;
		}
		if(mx < q - 1)
		for(int i = 1; i <= n; ++i) if(a[i] == 0) {
			a[i] = ++mx;
			if(mx == q - 1)
				break;
		}
		for(int i = 1; i <= n; ++i) if(a[i]) {
			fi = a[i];
			break;
		}
		if(a[1] == 0)
			a[1] = fi;
		for(int i = 2; i <= n; ++i) if(a[i] == 0) 
			a[i] = a[i - 1];
	}
	out:;
	if(flag) {
		printf("YES\n");
		for(int i = 1; i <= n; ++i)
			printf("%d%c", a[i], " \n"[i == n]);
	}
	else
		printf("NO\n");
	return 0;
}
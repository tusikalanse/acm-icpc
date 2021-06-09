#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int mx[N << 2], lazy[N << 2], n, k, l[N], a[N];

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		mx[rt << 1] += lazy[rt];
		mx[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		mx[rt] += val;
		lazy[rt] += val;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(mid >= L) 
		update(rt << 1, l, mid, L, R, val);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return mx[rt];
	pushdown(rt);
	int mid = l + r >> 1, ans = 0;
	if(mid >= L)
		ans = max(ans, query(rt << 1, l, mid, L, R));
	if(mid < R)
		ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	stack<int> stk;
	a[0] = 1e9;
	stk.push(0);
	for(int i = 1; i <= n; ++i) {
		while(a[stk.top()] < a[i])
			stk.pop();
		l[i] = stk.top();
		stk.push(i);
		//cout << "l[" << i << "] = " << l[i] << endl;
	}
	for(int i = 1; i <= n; ++i) {
		update(1, 1, n, l[i] + 1, i, 1);
		if(i >= k)
			printf("%d%c", query(1, 1, n, i - k + 1, i), " \n"[i == n]);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 50005;


int mmax[MAXN << 2], mmin[MAXN << 2];
int a[MAXN];

void pushup(int rt) {
	mmax[rt] = max(mmax[rt << 1], mmax[rt << 1 | 1]);
	mmin[rt] = min(mmin[rt << 1], mmin[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	if(l == r) {
		mmin[rt] = mmax[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l , mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		mmin[rt] = mmax[rt] = val;
		return;
	}
	int mid = l + r >> 1;
	if(mid <= pos) 
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int query_min(int rt, int l, int r, int L, int R) {
	if(l >= L && r <= R) 
		return mmin[rt];
	int mid = l + r >> 1;
	int res = 0x3f3f3f3f;
	if(mid >= L)
		res = min(res, query_min(rt << 1, l, mid, L, R));
	if(mid < R)
		res = min(res, query_min(rt << 1 | 1, mid + 1, r, L, R));
	return res;
}


int query_max(int rt, int l, int r, int L, int R) {
	if(l >= L && r <= R) 
		return mmax[rt];
	int mid = l + r >> 1;
	int res = -0x3f3f3f3f;
	if(mid >= L)
		res = max(res, query_max(rt << 1, l, mid, L, R));
	if(mid < R)
		res = max(res, query_max(rt << 1 | 1, mid + 1, r, L, R));
	return res;
}

int main() {
	int n, q, x, y;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	build(1, 1, n);
	while(q--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", query_max(1, 1, n, x, y) - query_min(1, 1, n, x, y));
	}
	return 0;
}
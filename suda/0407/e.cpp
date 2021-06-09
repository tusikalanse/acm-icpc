#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 200005;

int a[MAXN];

struct node {
	int l, r, mmin, mmax; 	
}Tree[MAXN << 2];

void pushup(int rt) {
	Tree[rt].mmin = min(Tree[rt << 1].mmin, Tree[rt << 1 | 1].mmin);
	Tree[rt].mmax = max(Tree[rt << 1].mmax, Tree[rt << 1 | 1].mmax);
}

void build(int rt, int l, int r) {
	Tree[rt].l = l;
	Tree[rt].r = r;
	if(l == r) {
		Tree[rt].mmin = Tree[rt].mmax = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int pos, int val) {
	if(Tree[rt].l == Tree[rt].r) {
		Tree[rt].mmin = val;
		Tree[rt].mmax = val;
		return;
	}
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	if(pos <= mid)
		update(rt << 1, pos, val);
	else
		update(rt << 1 | 1, pos, val);
	pushup(rt);
}

int query(int rt, int l, int r) {
	if(Tree[rt].l >= l && Tree[rt].r <= r) {
		return Tree[rt].mmin;
	}
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	int ans = 0x3f3f3f3f;
	if(mid >= l)
		ans = min(ans, query(rt << 1, l, r));
	if(mid < r)
		ans = min(ans, query(rt << 1 | 1, l, r));
	return ans;
}

int query2(int rt, int l, int r) {
	if(Tree[rt].l >= l && Tree[rt].r <= r) {
		return Tree[rt].mmax;
	}
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	int ans = -0x3f3f3f3f;
	if(mid >= l)
		ans = max(ans, query2(rt << 1, l, r));
	if(mid < r)
		ans = max(ans, query2(rt << 1 | 1, l, r));
	return ans;
}



int main() {
	int T, n, k, d, b, c;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &k);
		for(int i = 0; i < (1 << k); i++)
			scanf("%d", &a[i]);
		build(1, 0, (1 << k) - 1);
		scanf("%d", &n);
		while(n--) {
			scanf("%d %d %d", &d, &b, &c);
			if(d == 1) {
				long long ans;
				ans = 1LL * query(1, b, c) * query(1, b, c);
				ans = min(ans, 1LL * query(1, b, c) * query2(1, b, c));
				ans = min(ans, 1LL * query2(1, b, c) * query2(1, b, c));
				printf("%lld\n", ans);
			}
			else
				update(1, b, c);
		}
	}
	return 0;
}
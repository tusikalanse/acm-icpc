#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int s[100010];
int p[100010];
long long sp[100010];

struct node {
	long long mmin;
}Tree[100010 << 2];

void pushup(int rt) {
	Tree[rt].mmin = min(Tree[rt << 1].mmin, Tree[rt << 1 | 1].mmin);
}

void build(int rt, int l, int r) {
	if(l == r) {
		Tree[rt].mmin = sp[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

long long query(int rt, int l, int r, int L, int R) {
	if(l >= L && r <= R)
		return Tree[rt].mmin;
	int mid = l + r >> 1;
	long long res = 0x3f3f3f3f3f3f3f3f;
	if(mid >= L)
		res = min(res, query(rt << 1, l, mid, L, R));
	if(mid < R)
		res = min(res, query(rt << 1 | 1, mid + 1, r, L, R));
	return res;
}

int main() {
	int T, n, m, pgs;
	scanf("%d", &T);
	while(T--) {
		long long ans;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &s[i], &p[i]);
			sp[i] = 1LL * s[i] * p[i];
		}
		build(1, 0, n - 1);
		while(m--) {
			scanf("%d", &pgs);
			if(s[n - 1] <= pgs)
				printf("%lld\n", 1LL * p[n - 1] * pgs);
			else {
				int id = upper_bound(s,s+n,pgs)-s;
				ans = query(1, 0, n-1, id, n-1);
				if(id > 0) {
					if(s[id-1] <= pgs)
						ans = min(ans, 1LL * p[id-1] * pgs);
				}
				printf("%lld\n", ans);
			}
		}
	}


	return 0;
}
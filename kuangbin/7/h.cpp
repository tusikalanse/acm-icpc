#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll sum[100005 << 2], lst[100005];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];;
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = lst[l];
		return;	
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int L, int R) {
	if(l == r) {
		sum[rt] = (ll)sqrt(sum[rt]);
		return;
	}
	if(l >= L && r <= R && sum[rt] == r - l + 1)
		return;
	int mid = l + r >> 1;
	if(mid >= L)
		update(rt << 1, l, mid, L, R);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R);
	pushup(rt);
}

ll query(int rt, int l, int r, int L, int R) {
	if(l >= L && r <= R) {
		return sum[rt];
	}
	ll res = 0;
	int mid = l + r >> 1;
	if(mid >= L)
		res += query(rt << 1, l, mid, L, R);
	if(mid < R)
		res += query(rt << 1 | 1, mid + 1, r, L, R);
	return res;
}

int main() {
	int n, a, b, c, q, cas = 0;
	while(~scanf("%d", &n)) {
		printf("Case #%d:\n", ++cas);
		for(int i = 1; i <= n; ++i) {
			scanf("%lld", &lst[i]);
		}
		build(1, 1, n);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d %d", &a, &b, &c);
			if(b > c)
				b ^= c ^= b ^= c;
			if(a)
				printf("%lld\n", query(1, 1, n, b, c));
			else
				update(1, 1, n, b, c);
		}
		puts("");
	}
	return 0;
}
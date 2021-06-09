#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int num[N << 2], lazy[N << 2];
int n, T, o;
int a, b, c;
char op[10];

void build(int rt, int l, int r) {
	num[rt] = 1 << 1;
	lazy[rt] = 0;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void pushup(int rt) {
	num[rt] = num[rt << 1] | num[rt << 1 | 1];
}

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		num[rt << 1] = num[rt << 1 | 1] = 1 << lazy[rt];
		lazy[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R, int col) {
	if(L <= l && r <= R) {
		num[rt] = 1 << col;
		lazy[rt] = col;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(mid >= L)
		update(rt << 1, l, mid, L, R, col);
	if(mid < R) 
		update(rt << 1 | 1, mid + 1, r, L, R, col);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return num[rt];
	}
	pushdown(rt);
	int mid = l + r >> 1, ans = 0;
	if(mid >= L)
		ans |= query(rt << 1, l, mid, L, R);
	if(mid < R)
		ans |= query(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

int cnt(int n) {
	int ans = 0;
	while(n) {
		ans += (n & 1);
		n >>= 1;
	}
	return ans;
}

int main() {
	while(~scanf("%d%d%d", &n, &T, &o)) {
		build(1, 1, n);
		while(o--) {
			scanf("%s", op);
			if(op[0] == 'C') {
				scanf("%d%d%d", &a, &b, &c);
				if(a > b)
					swap(a, b);
				update(1, 1, n, a, b, c);
			}
			else {
				scanf("%d%d", &a, &b);
				if(a > b)
					swap(a, b);
				printf("%d\n", cnt(query(1, 1, n, a, b)));
			}
		}
	}
	return 0;
}
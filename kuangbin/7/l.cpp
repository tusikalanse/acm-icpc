#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 50005;

inline int getint() {
	char ch;
	int flag = 1, res = 0;
	ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-')
			flag *= -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0') {
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res * flag;
}

int n, m;

struct node {
	int sum, lazy;
}Tree[MAXN];

void pushup(int rt) {
	Tree[rt].sum = Tree[rt << 1].sum + Tree[rt << 1 | 1].sum;
}

void pushdown(int rt, int l, int r) {
	if(Tree[rt].lazy != 0) {
		Tree[rt << 1].lazy = Tree[rt << 1 | 1].lazy = Tree[rt].lazy;
		if(Tree[rt].lazy == 1) {
			Tree[rt << 1].sum = Tree[rt << 1 | 1].sum = 0;
		}
		else {
			int mid = l + r >> 1;
			Tree[rt << 1].sum = mid - l + 1;
			Tree[rt << 1 | 1].sum = r - mid;
		}
		Tree[rt].lazy = 0;
	}
}

void build(int rt, int l, int r) {
	Tree[rt].lazy = 0;
	if(l == r) {
		Tree[rt].sum = 1;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int L, int R, int p) {
	if(l >= L && r <= R) {
		if(p == 1) {
			Tree[rt].lazy = 1;
			Tree[rt].sum = 0;
		}
		else {
			Tree[rt].lazy = -1;
			Tree[rt].sum = r - l + 1;
		}
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L) 
		update(rt << 1, l, mid, L, R, p);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, p);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if(l >= L && r <= R) {
		return Tree[rt].sum;
	}
	if(Tree[rt].sum == 0)
		return 0;
	if(Tree[rt].sum == r - l + 1)
		return min(r, R) - max(l, L) + 1;
	pushdown(rt, l, r);
	int res = 0;
	int mid = l + r >> 1;
	if(mid >= L)
		res += query(rt << 1, l, mid, L, R);
	if(mid < R)
		res += query(rt << 1 | 1, mid + 1, r, L, R);
	return res;
}

int Find(int st, int num) {
	int res = -1;
	int l = st, r = n;
	while(l <= r) {
		int mid = l + r >> 1;
		int d = query(1, 1, n, l, mid);
		if(d >= num) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
			num -= d;
		}
	}
	return res;
}

int main() {
	int T;
	T = getint();
	while(T--) {
		n = getint();
		m = getint();
		build(1, 1, n);
		int K, A, B;
		while(m--) {
			K = getint();
			A = getint();
			B = getint();
			if(K == 1) {
				A++;
				int cnt = query(1, 1, n, A, n);
				if(cnt == 0) {
					puts("Can not put any one.");
				}
				else {
					int fi = Find(A, 1), se = Find(A, min(cnt, B));
					printf("%d %d\n", fi - 1, se - 1);
					update(1, 1, n, fi, se, 1);
				}
			}
			else {
				A++;
				B++;
				printf("%d\n", B - A + 1 - query(1, 1, n, A, B));
				update(1, 1, n, A, B, -1);
			}
		}
		puts("");
	}
	return 0;
}
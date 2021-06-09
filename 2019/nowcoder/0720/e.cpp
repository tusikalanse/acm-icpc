#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 5e4 + 10;
int n, m, q, b[N][10], x, y, z;
char s[14];

struct Matrix {
	int a[10][10];
	Matrix operator*(const Matrix &rhs) const {
		Matrix c;
		memset(c.a, 0, sizeof(c.a));
		for(int i = 0; i < m; ++i)  
			for(int j = 0; j < m; ++j) 
				for(int k = 0; k < m; ++k) 
					c.a[i][j] = (c.a[i][j] + 1LL * a[i][k] * rhs.a[k][j] % mod) % mod;
		return c;
	}
}tree[N << 2];

void pushup(int rt) {
	tree[rt] = tree[rt << 1] * tree[rt << 1 | 1];
}

void calc(int b[], Matrix &c) {
	memset(c.a, 0, sizeof(c.a));
	for(int i = 0; i < m; ++i) {
		for(int j = i; j < m && b[j] == 0; ++j) 
			c.a[i][j] = 1;
		for(int j = i; ~j && b[j] == 0; --j)
			c.a[i][j] = 1;
	}
}

void build(int rt, int l, int r) {
	if(l == r) {
		calc(b[l], tree[rt]);
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos) {
	if(l == r) {
		calc(b[l], tree[rt]);
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos);
	else
		update(rt << 1 | 1, mid + 1, r, pos);
	pushup(rt);
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s);
		for(int j = 0; j < m; ++j)
			b[i][j] = s[j] - '0';
	}
	build(1, 1, n);
	while(q--) {
		scanf("%d%d%d", &x, &y, &z);
		if(x == 1) {
			b[y][z - 1] ^= 1;
			update(1, 1, n, y);
		}
		else {
			printf("%d\n", tree[1].a[y - 1][z - 1]);
		}
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 100010, mod = 10007;

struct node {
	long long sum1, sum2, sum3; 
	int add, mul;
}Tree[MAXN << 2];

void pushup(int rt) {
	Tree[rt].sum1 = (Tree[rt << 1].sum1 + Tree[rt << 1 | 1].sum1) % mod;
	Tree[rt].sum2 = (Tree[rt << 1].sum2 + Tree[rt << 1 | 1].sum2) % mod;
	Tree[rt].sum3 = (Tree[rt << 1].sum3 + Tree[rt << 1 | 1].sum3) % mod;
}

void pushdown(int rt, int l, int r) {
	if(Tree[rt].add == 0 && Tree[rt].mul == 1)
		return;
	int mid = l + r >> 1;
	(Tree[rt << 1].sum3 = Tree[rt << 1].sum3 * Tree[rt].mul % mod * Tree[rt].mul % mod * Tree[rt].mul % mod\
		      + 3 * Tree[rt << 1].sum2 % mod * Tree[rt].mul % mod * Tree[rt].mul % mod * Tree[rt].add % mod\
		      + 3 * Tree[rt << 1].sum1 % mod * Tree[rt].mul % mod * Tree[rt].add % mod * Tree[rt].add % mod\
		   	   + 1LL *  (mid - l + 1) * Tree[rt].add % mod * Tree[rt].add % mod * Tree[rt].add % mod) %= mod;			
	(Tree[rt << 1 | 1].sum3 = Tree[rt << 1 | 1].sum3 * Tree[rt].mul % mod * Tree[rt].mul % mod * Tree[rt].mul % mod\
				  + 3 * Tree[rt << 1 | 1].sum2 % mod * Tree[rt].mul % mod * Tree[rt].mul % mod * Tree[rt].add % mod\
				  + 3 * Tree[rt << 1 | 1].sum1 % mod * Tree[rt].mul % mod * Tree[rt].add % mod * Tree[rt].add % mod\
				    	   + 1LL * (r - mid) * Tree[rt].add % mod * Tree[rt].add % mod * Tree[rt].add % mod) %= mod;	
	(Tree[rt << 1].sum2 = Tree[rt << 1].sum2 * Tree[rt].mul % mod * Tree[rt].mul % mod\
			  + 2 * Tree[rt << 1].sum1 % mod * Tree[rt].mul % mod * Tree[rt].add % mod\
			   + 1LL * (mid - l + 1) * Tree[rt].add % mod * Tree[rt].add % mod) %= mod;
	(Tree[rt << 1 | 1].sum2 = Tree[rt << 1 | 1].sum2 * Tree[rt].mul % mod * Tree[rt].mul % mod\
                  + 2 * Tree[rt << 1 | 1].sum1 % mod * Tree[rt].mul % mod * Tree[rt].add % mod\
				           + 1LL * (r - mid) * Tree[rt].add % mod * Tree[rt].add % mod) %= mod;
	((((Tree[rt << 1].sum1 *= Tree[rt].mul) %= mod) += 1LL * Tree[rt].add * (mid - l + 1) % mod) %= mod);
	((((Tree[rt << 1 | 1].sum1 *= Tree[rt].mul) %= mod) += 1LL * Tree[rt].add * (r - mid) % mod) %= mod);
	(Tree[rt << 1].mul *= Tree[rt].mul) %= mod;
	(Tree[rt << 1 | 1].mul *= Tree[rt].mul) %= mod; 
 	(((Tree[rt << 1].add *= Tree[rt].mul) %= mod) += Tree[rt].add) %= mod;
 	(((Tree[rt << 1 | 1].add *= Tree[rt].mul) %= mod) += Tree[rt].add) %= mod;
 	Tree[rt].mul = 1;
 	Tree[rt].add = 0;
}

void build(int rt, int l, int r) {
	Tree[rt].sum1 = Tree[rt].sum2 = Tree[rt].sum3 = Tree[rt].add = 0;
	Tree[rt].mul = 1;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void add(int rt, int l, int r, int L, int R, int val) {
	if(l >= L && r <= R) {
		(Tree[rt].sum3 = Tree[rt].sum3 + 3 * Tree[rt].sum2 % mod * val % mod\
		                   + 3 * Tree[rt].sum1 % mod * val % mod * val % mod\
		      + 1LL * (r - l + 1) * val % mod * val % mod * val % mod) %= mod;
		(Tree[rt].sum2 = Tree[rt].sum2 + 2 * Tree[rt].sum1 % mod * val % mod + 1LL * (r - l + 1) * val % mod * val % mod) %= mod;
		(Tree[rt].sum1 += 1LL * (r - l + 1) * val % mod) %= mod;
		(Tree[rt].add += val) %= mod;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L)
		add(rt << 1, l, mid, L, R, val);
	if(mid < R)
		add(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

void mul(int rt, int l, int r, int L, int R, int val) {
	if(l >= L && r <= R) {
		Tree[rt].sum3 = Tree[rt].sum3 * val % mod * val % mod * val % mod;
		Tree[rt].sum2 = Tree[rt].sum2 * val % mod * val % mod;
		Tree[rt].sum1 = Tree[rt].sum1 * val % mod;
		Tree[rt].add = Tree[rt].add * val % mod;
		Tree[rt].mul = Tree[rt].mul * val % mod;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L)
		mul(rt << 1, l, mid, L, R, val);
	if(mid < R)
		mul(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

void set(int rt, int l, int r, int L, int R, int val) {
	if(l >= L && r <= R) {
		Tree[rt].sum3 = 1LL * (r - l + 1) * val % mod * val % mod * val % mod;
		Tree[rt].sum2 = 1LL * (r - l + 1) * val % mod * val % mod;
		Tree[rt].sum1 = 1LL * (r - l + 1) * val % mod;
		Tree[rt].add = val;
		Tree[rt].mul = 0;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L)
		set(rt << 1, l, mid, L, R, val);
	if(mid < R)
		set(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

long long query(int rt, int l, int r, int L, int R, int p) {
	if(l >= L && r <= R) {
		if(p == 1)
			return Tree[rt].sum1;
		else if(p == 2)
			return Tree[rt].sum2;
		else
			return Tree[rt].sum3;
	}
	pushdown(rt, l, r);
	long long res = 0;
	int mid = l + r >> 1;
	if(mid >= L)
		res += query(rt << 1, l, mid, L, R, p);
	if(mid < R)
		res += query(rt << 1 | 1, mid + 1, r, L, R, p);
	return res % mod;
} 

int main() {
	int n, m, com, x, y, z;
	while(~scanf("%d %d", &n, &m) && n) {
		build(1, 1, n);
		while(m--) {
			scanf("%d %d %d %d", &com, &x, &y, &z);
			if(com == 1) {
				add(1, 1, n, x, y, z);
			}
			else if(com == 2) {
				mul(1, 1, n, x, y, z);
			}
			else if(com == 3) {
				set(1, 1, n, x, y, z);
			}
			else {
				printf("%lld\n", query(1, 1, n, x, y, z) % mod);
			}
		}
	}
	return 0;
}
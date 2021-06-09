#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


const int MAXN = 35005;
struct node
{
	int l, r, val, lazy;
}Tree[MAXN << 2];

void pushup(int rt){Tree[rt].val = Tree[rt << 1].val + Tree[rt << 1 | 1].val;}

void build(int rt, int l, int r){
	Tree[rt].l = l;
	Tree[rt].r = r;
	Tree[rt].lazy = 0;
	if(l == r){Tree[rt].val = a[l]; return;}
	else{
		int mid = (r+l) >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		pushup(rt);
	}
}

void update(int rt, int pos, int value){
	if(Tree[rt].l == Tree[rt].r) {Tree[rt].val = value; break;}
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	if (pos <= mid) update(rt << 1, pos, value);
	else update(rt << 1 | 1, pos, value);
	pushup(rt);
}

int query(int rt, int l, int r){
	if(Tree[rt].l >= l && Tree[rt].r <= r) return Tree[rt].val;
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	int ans = 0;
	if (l <= mid) ans += query(rt << 1, l, r);
	if (r > mid)  ans += query(rt << 1 | 1 ,l, r);
	return ans;
}

void pushdown(int rt){
	Tree[rt << 1].val += Tree[rt].lazy;
	Tree[rt << 1 | 1].val += Tree[rt].lazy;
	Tree[rt << 1].lazy += Tree[rt].lazy;
	Tree[rt << 1 | 1].lazy += Tree[rt].lazy;
	Tree[rt].lazy = 0;
}

void upgrade(int rt, int l, int r, int value){
	if(Tree[rt].l >= l && Tree[rt].r <= r){
		Tree[rt].lazy += value;
		Tree[rt].val += value;
	}
	if(Tree[rt].r < l || Tree[rt].l > r) return;
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	pushdown(rt);
	if (l <= mid) upgrade(rt << 1, l, r, value);
	if (mid < r)  upgrade(rt << 1 | 1, l, r, value);
	pushup(rt);
}


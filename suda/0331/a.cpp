#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 32005;
int level[MAXN];

struct node
{
	int l, r, sum;
}Tree[MAXN << 2];

void pushup(int rt) {
	Tree[rt].sum = Tree[rt << 1].sum + Tree[rt << 1 | 1].sum;
}

void build(int rt, int l, int r) {
	Tree[rt].l = l;
	Tree[rt].r = r;
	if(l == r) {
		Tree[rt].sum = 0;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int pos, int val) {
	if(Tree[rt].l == Tree[rt].r) {
		Tree[rt].sum += val;
		return;
	}
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	if(mid >= pos)
		update(rt << 1, pos, val);
	else
		update(rt << 1 | 1, pos, val);
	pushup(rt);
}

int query(int rt, int l, int r) {
	if(Tree[rt].l >= l && Tree[rt].r <= r)
		return Tree[rt].sum;
	int mid = Tree[rt].l + Tree[rt].r >> 1;
	int ans = 0;
	if(mid >= l)
		ans += query(rt << 1, l, r);
	if(mid < r)
		ans += query(rt << 1 | 1, l, r);
	return ans;
}

int main() {
	int n, x, y;
	build(1, 0, MAXN - 1);
	scanf("%d", &n);
	int t = n;
	while(t--) {
		scanf("%d%d", &x, &y);
		level[query(1, 0, x)]++;
		update(1, x, 1);
	}
	for(int i = 0; i < n; i++)
		printf("%d\n", level[i]);
	return 0;
}
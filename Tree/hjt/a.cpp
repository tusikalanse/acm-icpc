#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100010;
struct node {
	int l, r, sum;
}Tree[MAXN * 20];
int root[MAXN];

struct num {
	int x, id;
	bool operator < (const num &rhs) const {
		return x < rhs.x;
	}
}a[MAXN];

int rnk[MAXN];
int n, m, i, j, k, cnt;

void init() {
	cnt = 0;
	root[0] = 0;
	Tree[0].l = Tree[0].r = Tree[0].sum = 0;
}

void update(int &rt, int l, int r, int num) {
	Tree[++cnt] = Tree[rt];
	rt = cnt;
	Tree[rt].sum++;
	if(l == r)
		return;
	int mid = l + r >> 1;
	if(num <= mid)
		update(Tree[rt].l, l, mid, num);
	else
		update(Tree[rt].r, mid + 1, r, num);
}

int query(int i, int j, int k, int l, int r) {
	if(l == r)
		return l;
	int mid = l + r >> 1;
	int d = Tree[Tree[j].l].sum - Tree[Tree[i].l].sum;
	if(k <= d)
		return query(Tree[i].l, Tree[j].l, k, l, mid);
	else
		return query(Tree[i].r, Tree[j].r, k - d, mid + 1, r);
}

int main() {
	scanf("%d %d", &n, &m);
	init();
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].x);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		rnk[a[i].id] = i;
	}
	for(int i = 1; i <= n; ++i) {
		root[i] = root[i - 1];
		update(root[i], 1, n, rnk[i]);
	}
	while(m--) {
		scanf("%d %d %d", &i, &j, &k);
		printf("%d\n", a[query(root[i - 1], root[j], k, 1, n)].x);
	}
	return 0;
}
`
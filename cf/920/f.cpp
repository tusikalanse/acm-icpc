#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300005;

int i, j, d[1000002], a[MAXN];

struct node
{
	int l, r, mx;
	long long sum;
}Tree[MAXN << 2];

void pushup(int rt){
	Tree[rt].sum = Tree[rt << 1].sum + Tree[rt << 1 | 1].sum;
	Tree[rt].mx = max(Tree[rt << 1].mx, Tree[rt << 1 | 1].mx);
}

void build(int rt, int l, int r){
	Tree[rt].l = l;
	Tree[rt].r = r;
	if(l == r){
		Tree[rt].sum = Tree[rt].mx = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r){
	if(Tree[rt].mx <= 2)
		return;
	if(Tree[rt].l == Tree[rt].r){
		Tree[rt].sum = Tree[rt].mx = d[Tree[rt].sum];
		return;
	}
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	if(mid >= r)
		update(rt << 1, l, r);
	else if(mid < l)
		update(rt << 1 | 1, l, r);
	else{
		update(rt << 1, l, mid);
		update(rt << 1 | 1, mid + 1, r);
	}
	pushup(rt);
}

long long query(int rt, int l, int r){
	if(Tree[rt].l >= l && Tree[rt].r <= r)
		return Tree[rt].sum;
	long long ans = 0; 
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	if(mid >= l) ans += query(rt << 1, l, r);
	if(mid < r)  ans += query(rt << 1 | 1, l, r);
	return ans;
}

int main(){
	int n, m, i, j, c, x, y;
	for(i=1;i<=1000000;i++)
		for(j=i;j<=1000000;j+=i)
			d[j]++;
	scanf("%d %d", &n, &m);
	for(i = 1; i<=n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	for(i = 1; i<=m; i++){
		scanf("%d %d %d", &c, &x, &y);
		if(c == 1){
			update(1, x, y);
		}
		else
			printf("%lld\n", query(1, x, y));
	}
	return 0;
}
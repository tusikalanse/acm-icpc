#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000+5;
int a[MAXN];
struct node{int l, r, sum;}Tree[MAXN << 2];


void addsum(int rt){Tree[rt].sum = max(Tree[rt << 1].sum, Tree[rt << 1 | 1].sum);}


void build(int rt, int l, int r){
	Tree[rt].l = l;
	Tree[rt].r = r;
	if(l == r) {Tree[rt].sum = a[l]; return;}
	int mid = (l+r)/2;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid+1, r);
	addsum(rt);
}

void update(int rt, int pos, int val){
	if(Tree[rt].l == Tree[rt].r) {Tree[rt].sum = val; return;}
	int mid = (Tree[rt].l + Tree[rt].r)/2;
	if(pos <= mid) update(rt << 1, pos, val);
	else update(rt << 1 | 1, pos, val);
	addsum(rt);
}

int query(int rt, int l, int r){
	if (Tree[rt].l >= l && Tree[rt].r <= r) return Tree[rt].sum;
	int mid = (Tree[rt].l + Tree[rt].r)/2;
	int ans = 0;
	if (l <= mid) ans = query(rt << 1, l, r);
	if (mid < r) ans = max(ans, query(rt << 1 | 1, l, r));
	return ans;
}



int main(){
	int n, m;
	int x, y;
	char com[6];
	while(~scanf("%d%d", &n, &m)){
	for(int i = 1; i<=n; i++) scanf("%d", a+i);
	build(1, 1, n);
	while(m--){
		scanf("%s %d %d", com, &x, &y);
	switch (com[0]){
	case 'U':
		update(1, x, y);
		break;
	case 'Q':
		printf("%d\n", query(1, x, y));
		break;
	}
	}
	}
	return 0;
}


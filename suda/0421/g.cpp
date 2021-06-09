#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e5 +10;

int le[MAXN], ri[MAXN];
char s[MAXN];

struct node
{
	int l, r, d;	
}Tree[MAXN << 2];

void pushup(int rt) {
	Tree[rt].d = min(Tree[rt << 1].d, Tree[rt << 1 | 1].d);
}

void build(int rt, int l, int r) {
	Tree[rt].l = l;
	Tree[rt].r = r;
	if(l == r) {
		Tree[rt].d = le[l] - ri[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

int query(int rt, int l, int r) {
	if(Tree[rt].l >= l && Tree[rt].r <= r)
		return Tree[rt].d;
	int ans = MAXN * 100;
	int mid = (Tree[rt].l + Tree[rt].r) >> 1;
	if(mid >= l)
		ans = min(ans, query(rt << 1, l, r));
	if(mid < r)
		ans = min(ans, query(rt << 1 | 1, l ,r));
	return ans;
}

int main() {
	int n, q;
	while(~scanf("%d %d", &n, &q)) {
		memset(le, 0, sizeof(le));
		memset(ri, 0, sizeof(ri));
		scanf("%s", s +1);
		for(int i = 1; i <= n; ++i) {
			le[i] = le[i-1];
			ri[i] = ri[i-1];
			if(s[i] == '(')
				le[i]++;
			else
				ri[i]++;
		}
		build(1, 1, n);
		while(q--) {
			int x, y;
			scanf("%d %d", &x, &y);
			if(x > y)
				x ^= y ^= x ^= y;
//			cout << query(1, x, y-1) << endl;
			if(s[x] == s[y])
				puts("Yes");
			else if(s[x] == '(') {
				if(query(1, x, y-1) >= 2)
					puts("Yes");
				else 
					puts("No");
			}
			else 
				puts("Yes");
		}
	}
	return 0;
}

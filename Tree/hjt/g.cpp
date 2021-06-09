#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 100010;
int lst[MAXN], cnt;

struct node {
	int l, r, lazy;
	long long sum;
}Tree[MAXN * 30];
int root[MAXN];

void pushup(int rt, int l, int r) {
	Tree[rt].sum = Tree[Tree[rt].l].sum + Tree[Tree[rt].r].sum + 1LL * (r - l + 1) * Tree[rt].lazy;
}

void build(int &rt, int l, int r) {
	rt = ++cnt;
	Tree[rt].lazy = 0;
	if(l == r) {
		Tree[rt].sum = lst[l];
		Tree[rt].l = Tree[rt].r = 0;
		return;
	}
	int mid = l + r >> 1;
	build(Tree[rt].l, l, mid);
	build(Tree[rt].r, mid + 1, r);
	pushup(rt, l, r);
}

void update(int &rt, int l, int r, int L, int R, int num) {
	Tree[++cnt] = Tree[rt];
	rt = cnt;
	if(l >= L && r <= R) {
		Tree[rt].sum += 1LL * (r - l + 1) * num;
		Tree[rt].lazy += num;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= L)
		update(Tree[rt].l, l, mid, L, R, num);
	if(mid < R)
		update(Tree[rt].r, mid + 1, r, L, R, num);
	pushup(rt, l, r);
}

ll query(int rt, int l, int r, int L, int R, long long add) {
	ll ans = 0;
	if(l >= L && r <= R) {
		return Tree[rt].sum + 1LL * add * (r - l + 1);
	}
	int mid = l + r >> 1;
	add += Tree[rt].lazy;
	if(mid >= L)
		ans += query(Tree[rt].l, l, mid, L, R, add);
	if(mid < R)
		ans += query(Tree[rt].r, mid + 1, r, L, R, add);
	return ans;
}

int main() {
	int n, m, cas = 0, t, l, r, d;
	char ch[10];
	while(~scanf("%d %d", &n, &m)) {
		if(cas)
			puts("");
		cas++;
		for(int i = 1; i <= n; ++i)
			scanf("%d", &lst[i]);
		cnt = 0;
		t = 0;
		root[0] = 0;
		build(root[0], 1, n);
		while(m--) {
			scanf("%s", ch);
			if(ch[0] == 'C') {
				root[t + 1] = root[t];
				t++;
				scanf("%d %d %d", &l, &r, &d);
				update(root[t], 1, n, l, r, d);
			}
			else if(ch[0] == 'B') {
				scanf("%d", &t);
				cnt = root[t + 1];
			}
			else if(ch[0] == 'Q') {
				scanf("%d %d", &l, &r);
				printf("%lld\n", query(root[t], 1, n, l, r, 0));
			}
			else {
				scanf("%d %d %d", &l, &r, &d);
				printf("%lld\n", query(root[d], 1, n, l, r, 0));
			}
		}
	}
	return 0;
}
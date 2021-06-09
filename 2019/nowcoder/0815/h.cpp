#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct node {
	int l, r, cnt;
	long long sum;
}Tree[N * 20];
int root[N];

int cnt;

void init() {
	cnt = 0;
	root[0] = 0;
	Tree[0].l = Tree[0].r = Tree[0].cnt = Tree[0].sum = 0;
}

void update(int &rt, int l, int r, int num) {
	Tree[++cnt] = Tree[rt];
	rt = cnt;
	Tree[rt].cnt++;
	Tree[rt].sum += num;
	if(l == r)
		return;
	int mid = l + r >> 1;
	if(num <= mid)
		update(Tree[rt].l, l, mid, num);
	else
		update(Tree[rt].r, mid + 1, r, num);
}

pair<int, long long> query(int i, int j, int num, int l, int r) {
	if(l == r)
		return make_pair(Tree[j].cnt - Tree[i].cnt, Tree[j].sum - Tree[i].sum);
	int mid = l + r >> 1;
	if(num <= mid) 
		return query(Tree[i].l, Tree[j].l, num, l, mid);
	pair<int, long long> tmp = query(Tree[i].r, Tree[j].r, num, mid + 1, r);
	return make_pair(Tree[Tree[j].l].cnt - Tree[Tree[i].l].cnt + tmp.first, Tree[Tree[j].l].sum - Tree[Tree[i].l].sum + tmp.second);
}

int n, q, l, r, x, y;
int h[N];
long long sumh[N];

double check(double height) {
	if(height < 1) 
		return (r - l + 1) * height;
	int c; long long s;
	tie(c, s) = query(root[l - 1], root[r], (int)height, 1, 100000);
	return s + (r - l + 1 - c) * height;
}

int main() {
	init();
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &h[i]);
		root[i] = root[i - 1];
		update(root[i], 1, 100000, h[i]);
		sumh[i] = sumh[i - 1] + h[i];
	}
	while(q--) {
		scanf("%d%d%d%d", &l, &r, &x, &y);
		int ll = 0, rr = 1e5, ans;
		double tar = (1.0 * y - x) / y * (sumh[r] - sumh[l - 1]);
		while(ll <= rr) {
			int mid = ll + rr >> 1;
			if(check(mid) <= tar) {
				ans = mid;
				ll = mid + 1;
			}
			else {
				rr = mid - 1;
			}
		}
		double o, lll = ans, rrr = ans + 1;
		for(int _ = 0; _ <= 50; ++_) {
			o = (lll + rrr) / 2;
			if(check(o) <= tar) 
				lll = o;
			else
				rrr = o;
		}
		printf("%.15f\n", o);
	}
	return 0;
}
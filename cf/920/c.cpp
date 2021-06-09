#include <bits/stdc++.h>
using namespace std;


const int MAXN = 200006;
struct no
{
	int id, pos, per;
}lis[MAXN];
struct node{int l, r, sum;}Tree[MAXN << 2];
void pushup(int rt){Tree[rt].sum = Tree[rt << 1].sum & Tree[rt << 1 | 1].sum;}
void build(int rt, int l, int r){
	Tree[rt].l = l;
	Tree[rt].r = r;
	if(l == r) {Tree[rt].sum = lis[l].per; return;}
	int mid = (l+r)/2;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid+1, r);
	pushup(rt);
}
int query(int rt, int l, int r){
	if (Tree[rt].l >= l && Tree[rt].r <= r) return Tree[rt].sum;
	int mid = (Tree[rt].l + Tree[rt].r)/2;
	int ans = 1;
	if (l <= mid) ans &= query(rt << 1, l, r);
	if (mid < r) ans &= query(rt << 1 | 1, l, r);
	return ans;
}
int main(){
	int len, t, flag = 1, left, right;
	scanf("%d", &len);
	for(int i = 1; i<=len; i++){
		scanf("%d", &lis[i].pos);
		lis[i].id = i;
	}
	getchar();
	for(int i = 1; i<len; i++){
		lis[i].per = getchar() - '0';
	}
	build(1, 1, len-1);
	for(int i = 1; i<=len; i++){
		left = min(lis[i].id, lis[i].pos);
		right = max(lis[i].id, lis[i].pos);
		flag = query(1, left, right-1);
		if(flag == 0) goto nxt;
	}
	nxt:;
	puts(flag?"YES":"NO");
	return 0;
}

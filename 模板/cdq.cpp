#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10, K = 4;
long long ans;
int n;

struct node {
	int d[K], tag[K];
}Q[K][N];

bool cmp(node &x, node &y, int k) {
	if(k == K - 1)
		return x.d[k] < y.d[k];
	return x.d[k] < y.d[k] || (x.d[k] == y.d[k] && x.d[k + 1] < y.d[k + 1]);
}

bool judge(node &x, int f) {
	for(int i = 1; i < K - 1; ++i) 
		if(x.tag[i] != f)
			return 0;
	return 1;
}

void CDQ(int l, int r, int k) {
	if(l == r) return;
	int mid = l + r >> 1, i = l, j = mid + 1, p = l, sum = 0;
	CDQ(l, mid, k); CDQ(mid + 1, r, k);
	while(i <= mid && j <= r) {
		if(cmp(Q[k - 1][i], Q[k - 1][j], k)) {
			if(k == K - 1 && judge(Q[k - 1][i], 0)) sum++;
			Q[k][p] = Q[k - 1][i++];
			Q[k][p++].tag[k] = 0;
		}
		else {
			if(k == K - 1 && judge(Q[k - 1][j], 1)) ans += sum;
			Q[k][p] = Q[k - 1][j++];
			Q[k][p++].tag[k] = 1;
		}
	}
	while(i <= mid) {
		if(k == K - 1 && judge(Q[k - 1][i], 0)) sum++;
		Q[k][p] = Q[k - 1][i++];
		Q[k][p++].tag[k] = 0;
	}
	while(j <= r) {
		if(k == K - 1 && judge(Q[k - 1][j], 1)) ans += sum;
		Q[k][p] = Q[k - 1][j++];
		Q[k][p++].tag[k] = 1;
	}
	for(int i = l; i <= r; ++i)
		Q[k - 1][i] = Q[k][i];
	if(k != K - 1)
		CDQ(l, r, k + 1);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &Q[0][i].d[1]);
		Q[0][i].d[0] = i;
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &Q[0][i].d[2]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &Q[0][i].d[3]);
	}
	CDQ(1, n, 1);
	printf("%lld\n", ans);
	return 0;
}
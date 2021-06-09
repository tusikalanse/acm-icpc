#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct P {
	int x, y;
	char op[3];
}a[N];

long long ans;
int b[N], totx, toty;
int T, n, m, K;
vector<int> in[N], out[N], le[N], ri[N];
int sum[N << 2];
void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = 0;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		sum[rt] += val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid) update(rt << 1, l, mid, pos, val);
	else update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return sum[rt];
	int mid = l + r >> 1, ans = 0;
	if(L <= mid) ans += query(rt << 1, l, mid, L, R);
	if(R > mid) ans += query(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d%d%d", &n, &m, &K);
		for(int i = 1; i <= K; ++i) {
			scanf("%d%d%s", &a[i].x, &a[i].y, a[i].op);
			b[i] = a[i].x;
		}
		sort(b + 1, b + K + 1);
		totx = unique(b + 1, b + K + 1) - b - 1;
		for(int i = 1; i <= K; ++i) 
			a[i].x = lower_bound(b + 1, b + totx + 1, a[i].x) - b;
		for(int i = 1; i <= K; ++i) 
			b[i] = a[i].y;
		sort(b + 1, b + K + 1);
		toty = unique(b + 1, b + K + 1) - b - 1;
		for(int i = 1; i <= K; ++i) 
			a[i].y = lower_bound(b + 1, b + toty + 1, a[i].y) - b;
		build(1, 1, totx);
		for(int i = 1; i <= K; ++i) 
			in[i].clear(), out[i].clear(), le[i].clear(), ri[i].clear();
		for(int i = 1; i <= K; ++i) {
			if(a[i].op[0] == 'U')
				in[a[i].y].push_back(a[i].x);
			else if(a[i].op[0] == 'D') {
				out[a[i].y].push_back(a[i].x);
				update(1, 1, totx, a[i].x, 1);
			}
			else if(a[i].op[0] == 'L') 
				le[a[i].y].push_back(a[i].x);
			else
				ri[a[i].y].push_back(a[i].x);
		}
		for(int i = 1; i <= toty; ++i) {
			for(auto f: in[i])
				update(1, 1, totx, f, 1);
			int l = 0, r = 1e9;
			for(auto f: le[i])
				l = max(l, f);
			for(auto f: ri[i])
				r = min(r, f);
			if(l >= r) 
				ans += sum[1];
			else {
				if(l != 0)
					ans += query(1, 1, totx, 1, l);
				if(r != 1e9)
					ans += query(1, 1, totx, r, totx);
			}
			//cout << "ans = " << ans << endl;
			for(auto f: out[i])
				update(1, 1, totx, f, -1);
		}
		printf("%lld\n", ans + 1);
	}
	return 0;
}
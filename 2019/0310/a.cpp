#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct line {
	int down, up;
	int id_down, id_up;
}lines[N];

map<int, int> mp;
vector<int> in[N], out[N];
int n, m, a[N], b[N], ans, cnt;

int mx[N << 2], lazy[N << 2];

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		mx[rt << 1] += lazy[rt];
		mx[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		lazy[rt] += val;
		mx[rt] += val;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(mid >= L)
		update(rt << 1, l, mid, L, R, val);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%*d%d%*d%d", &lines[i].up, &lines[i].down);
		a[i * 2 - 1] = lines[i].up;
		a[i * 2] = lines[i].down;
		b[i * 2 - 1] = lines[i].up;
		b[i * 2] = lines[i].down;
	}
	sort(b + 1, b + 2 * n + 1);
	m = unique(b + 1, b + 2 * n + 1) - b;
	for(int i = 1; i <= n; ++i) {
		lines[i].id_down = upper_bound(b + 1, b + m + 1, lines[i].down) - b;
		lines[i].id_up = upper_bound(b + 1, b + m + 1, lines[i].up) - b;
		in[lines[i].id_down].push_back(i);
		out[lines[i].id_up + 1].push_back(i);
	}
	for(int i = 1; i <= n; ++i) {
		update(1, 1, m, lines[i].id_down, lines[i].id_up, 1);
	}
	for(int i = 1; i <= m; ++i) {
		for(auto &j: in[i]) {
			update(1, 1, m, lines[j].id_down, lines[j].id_up, -1);
			cnt++;
		}
		for(auto &j: out[i]) {
			update(1, 1, m, lines[j].id_down, lines[j].id_up, 1);
			cnt--;
		}
		//cout << b[i] << " " << cnt + mx[1] << endl;
		ans = max(ans, cnt + mx[1]);
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int c[N], n, q, basis[20], pos[20], ans[N], r;

struct edge {
	int l, r, id;
	bool operator<(const edge &rhs) const {
		return r < rhs.r;
	}
}ask[N];

void insert(int x, int id) {
	for(int i = 19; ~i; --i) {
		if((x >> i) & 1) {
			if(basis[i] == 0) {
				basis[i] = x;
				pos[i] = id;
				break;
			}
			else {
				if(pos[i] < id)
					swap(basis[i], x), swap(pos[i], id);
				x ^= basis[i];
			}
		}
	}
}

int query(int l) {
	int ans = 0;
	for(int i = 19; ~i; --i) {
		if(pos[i] >= l) {
			if((ans ^ basis[i]) > ans) {
				ans = ans ^ basis[i];
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) {
		ask[i].id = i;
		scanf("%d%d", &ask[i].l, &ask[i].r);
	}
	sort(ask + 1, ask + q + 1);
	r = 0;
	for(int i = 1; i <= q; ++i) {
		while(r < ask[i].r) {
			r++;
			insert(c[r], r);
		}
		ans[ask[i].id] = query(ask[i].l);
	}
	for(int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
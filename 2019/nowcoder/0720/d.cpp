#include <bits/stdc++.h>
using namespace std;
using bs = bitset<105>;
using LL = long long;

struct node {
	LL val;
	bs mask;
	bool operator<(const node &rhs) const {
		return val > rhs.val;
	}
};

int s[105][105], n, a[105], k;
bs f[105];


int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; ++i) {
		f[i].reset();
		for(int j = 0; j < n; ++j) {
			scanf("%1d", &s[i][j]);
			if(s[i][j] == 1)
				f[i].set(j);
		}
	}
	priority_queue<node> pq;
	bs p;
	p.reset();
	pq.push({0, p});
	while(!pq.empty()) {
		node u = pq.top();
		pq.pop();
		if(--k == 0) {
			printf("%lld\n", u.val);
			return 0;
		}
		int pos = 0;
		for(int i = 0; i < n; ++i)
			if(u.mask[i])
				pos = i + 1;
		for(int i = pos; i < n; ++i) if((f[i] & u.mask) == u.mask) {
			u.mask[i] = 1;
			pq.push({u.val + a[i], u.mask});
			u.mask[i] = 0;
		}
	}
	puts("-1");
	return 0;
}
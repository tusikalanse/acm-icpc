#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, blk;
struct Q {
	int l, r, t, id;
	bool operator<(const Q &rhs) const {
		return l / blk == rhs.l / blk ? (r / blk == rhs.r / blk ? t < rhs.t : r < rhs.r) : l < rhs.l;
	}
}q[N];

long long sum;
int cnt[1048576 + 10];
int a[N], s[N], qcnt, ccnt, op, L, R, T, pos, c[N];
long long ans[N];

inline void add(int x) {
	sum += cnt[s[x]]++;
}

inline void sub(int x) {
	sum -= --cnt[s[x]];
}

inline void modify(int i, int t) {
	if(q[i].l <= c[t] && c[t] <= q[i].r) sub(c[t]);
	(s[c[t]] ^= a[c[t]]) ^= a[c[t] + 1];
	swap(a[c[t]], a[c[t] + 1]);
	if(q[i].l <= c[t] && c[t] <= q[i].r) add(c[t]);
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(cnt, 0, sizeof(cnt));
		sum = qcnt = ccnt = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			s[i] = s[i - 1] ^ a[i];
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%d", &op);
			if(op == 1) {
				scanf("%d%d", &L, &R);
				++qcnt;
				q[qcnt] = {L - 1, R, ccnt, qcnt};
			}
			else {
				scanf("%d", &pos);
				c[++ccnt] = pos;
			}
		}
		blk = (int)pow(n, 2.0 / 3);
		sort(q + 1, q + qcnt + 1);
		L = 0; R = 1; T = 0; cnt[0] = 1; cnt[s[1]]++; sum = (s[1] == 0); 
		for(int i = 1; i <= qcnt; ++i) {
			while(L < q[i].l) sub(L++);
			while(L > q[i].l) add(--L);
			while(R < q[i].r) add(++R);
			while(R > q[i].r) sub(R--);
			while(T < q[i].t) modify(i, ++T);
			while(T > q[i].t) modify(i, T--);
			ans[q[i].id] = 1LL * (q[i].r - q[i].l) * (q[i].r - q[i].l + 1) / 2 - sum;
		}
		for(int i = 1; i <= qcnt; ++i) {
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}
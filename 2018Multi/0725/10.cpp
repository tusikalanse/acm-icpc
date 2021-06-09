#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MAXN = 1e5 + 10;

int t[MAXN], c[MAXN], a[MAXN];
int n, x, y, m;


inline int lowbit(int x) {return x & -x;}
inline void update(int x, int v) {
	for(int i = x; i <= n; i += lowbit(i))
		c[i] += v;
}
inline LL sum(int x) {
	LL ans = 0;
	for(int i = x; i > 0; i -= lowbit(i))
		ans += c[i];
	return ans;
}


int main() {
	while(~scanf("%d",&n)) {
		scanf("%d%d",&x,&y);
		memset(c, 0, sizeof(c));
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]), t[i] = a[i];
		sort(t + 1, t + n + 1);
		m = unique(t + 1, t + n + 1) - t - 1;
		for(int i = 1; i <= n; ++i)
			a[i] = lower_bound(t + 1, t + 1 + m, a[i]) - t;
		LL ans = 0;
		for(int i = n; i > 0; --i) {
			ans += sum(a[i] - 1);
			update(a[i], 1);
		}
		printf("%lld\n", min(x, y) * ans);
	}
	return 0;
}
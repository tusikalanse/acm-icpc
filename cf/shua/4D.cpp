#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int dp[N], nxt[N];
struct envelope {
	int w, h, id;
	bool operator<(const envelope &rhs) const {
		if(w == rhs.w) 
			return h < rhs.h;
		return w < rhs.w;
	}
}a[N];
int n, w, h, ans;

int main() {
	scanf("%d%d%d", &n, &w, &h);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].w, &a[i].h);
		a[i].id = i;
		dp[i] = 1;
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i; --i) {
		for(int j = 1; j < i; ++j) {
			if(a[j].w < a[i].w && a[j].h < a[i].h && dp[j] < dp[i] + 1) {
				dp[j] = dp[i] + 1;
				nxt[j] = i;
			}
		}
		if(a[i].w > w && a[i].h > h && dp[i] > dp[ans])
			ans = i;
	}
	printf("%d\n", dp[ans]);
	if(ans)
		printf("%d", a[ans].id);
	while(nxt[ans]) {
		ans = nxt[ans];
		printf(" %d", a[ans].id);
		if(nxt[ans] == 0)
			puts("");
	}
	return 0;
}
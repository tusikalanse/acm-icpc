#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, k, a[N], cnt;
long long ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		ans = k; cnt = 1;
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		priority_queue<int, vector<int>, greater<int>> que1;
		priority_queue<int> que2;
		sort(a + 1, a + n + 1, greater<int>());
		int i;
		for(i = 1; i <= n && a[i] >= k; ++i) {
			cnt += a[i] / k;
			ans += a[i];
			if(a[i] % k)
				que1.push(k * (1 + (a[i] - 1) / k) - a[i]);
		}
		if(cnt >= n) {
			for(; i <= n; ++i)
				ans += a[i];
		}
		else {
			for(; i <= n; ++i) {
				if(cnt < n) {
					cnt++;
					ans += k;
					que2.push(k - a[i]);
				}
				else 
					ans += a[i];
			}
		}
		while(!que1.empty() && !que2.empty() && que1.top() < que2.top()) {
			ans += que1.top();
			ans -= que2.top();
			que1.pop(); que2.pop();
		}
		printf("%lld\n", ans);
	}
	return 0;
}
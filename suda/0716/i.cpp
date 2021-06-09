#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;

int a[200010];
int sum[200010];

int main() {
	int T, n, k, l, r, m;
	scanf("%d", &T);
	while(T--) {
		int ans = -0x3f3f3f3f;
		scanf("%d %d", &n, &k);
		m = n;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			a[i + n] = a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		for(int i = n + 1; i < n + k; ++i) 
			sum[i] = sum[i - 1] + a[i];
		n = n + k - 1;
		deque<int> q;
		for(int i = 1; i <= n; ++i) {
			while(!q.empty() && sum[i - 1] < sum[q.back()])
				q.pop_back();
			while(!q.empty() && q.front() < i - k)
				q.pop_front();
			q.push_back(i - 1);
			if(sum[i] - sum[q.front()] > ans) {
				ans = sum[i] - sum[q.front()];
				l = q.front() + 1;
				r = i;
			}
		}
		if(r > m)
			r -= m;
		printf("%d %d %d\n", ans, l, r);
	}
	return 0;
}
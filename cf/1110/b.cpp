#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, k, l, r, b[N], ans;


priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		if(i != 1)
			pq.push(b[i] - b[i - 1] - 1);
	}
	ans = n;
	k = n - k;
	while(k--) {
		ans += pq.top();
		pq.pop();
	}
	printf("%d\n", ans);
	return 0;
}
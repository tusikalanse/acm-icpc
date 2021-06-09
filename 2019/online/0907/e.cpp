#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, m, w[N], ans[N], mx = -1;
pair<int, int> b[N], que[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		b[i].first = w[i];
		b[i].second = i;
		que[i].first = w[i] + m;
		que[i].second = i;
	}
	sort(b + 1, b + n + 1);
	sort(que + 1, que + n + 1);
	int j = n;
	for(int i = n; i; --i) {
		while(j && b[j].first >= que[i].first) {
			mx = max(b[j].second, mx);
			j--;
		}
		if(mx <= que[i].second) {
			ans[que[i].second] = -1;
		}
		else
			ans[que[i].second] = mx - que[i].second - 1;
	}
	for(int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}
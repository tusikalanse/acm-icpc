#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

pair<int, int> a[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d%d", &a[i].second, &a[i].first);
	sort(a + 1, a + n + 1);
	int now = 0, ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(now >= a[i].second) continue;
		now = a[i].first;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
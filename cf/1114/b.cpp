#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, k;
long long sum;
pair<int, int> a[N];
vector<int> v;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= m * k; ++i) {
		sum += a[i].first;
		v.push_back(a[i].second);
	}
	printf("%lld\n", sum);
	sort(v.begin(), v.end());
	int pre = 0;
	for(int i = 1; i < k; ++i) {
		printf("%d%c", v[i * m - 1], " \n"[i == k - 1]);
	}
	return 0;
}
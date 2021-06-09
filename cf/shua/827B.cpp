#include <bits/stdc++.h>
using namespace std;

int n, k, t, d[200010];
vector<int> v;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; ++i) {
		v.push_back((n - 1) / k);
		d[i] = 1;
	}
	t = (n - 1) % k;
	for(int i = 0; i < t; ++i)
		v[i]++;
	printf("%d\n", v[0] + v[1]);
	t = 0;
	for(int i = 2; i <= n; ++i) {
		printf("%d %d\n", d[t], i);
		d[t] = i;
		t = (t + 1) % k;
	}
	return 0;
}
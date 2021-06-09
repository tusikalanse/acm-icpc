#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, L[N], R[N], md[N], m;
long long tmp, ans;
int b[N * 3];
int in[N * 3], change[N * 3], out[N * 3];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &L[i], &R[i]);
		L[i] = 2 * L[i] - 1;
		R[i] = 2 * R[i] - 1;
		md[i] = (0LL + L[i] + R[i]) / 2;
		b[3 * i - 2] = L[i];
		b[3 * i - 1] = R[i];
		b[3 * i] = md[i];
	}
	tmp = ans = 0;
	sort(b + 1, b + 3 * n + 1);
	m = unique(b + 1, b + 3 * n + 1) - b - 1;
	for(int i = 1; i <= n; ++i) {
		in[lower_bound(b + 1, b + m + 1, L[i]) - b]++;
		change[lower_bound(b + 1, b + m + 1, md[i]) - b]++;
		out[lower_bound(b + 1, b + m + 1, R[i]) - b]++;
	}
	int down = 0, up = 0;
	down += in[1];
	for(int i = 2; i <= m; ++i) {
		tmp += 1LL * (down - up) * (b[i] - b[i - 1]);
		ans = max(ans, tmp);
		down += in[i];
		down -= change[i];
		up += change[i];
		up -= out[i];
	}
	printf("%lld\n", ans);
	return 0;
}
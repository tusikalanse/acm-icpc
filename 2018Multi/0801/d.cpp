#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int b[120];

int n, m, T, ans;
int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%*d%d", &b[i]);
		}
		sort(b + 1, b + 1 + n);
		for(int i = 1; i <= n; ++i) {
			m /= (1 + b[i]);
			if(m >= 1)
				ans = i;
			else
				break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
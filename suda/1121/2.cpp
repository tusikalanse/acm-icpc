#include <bits/stdc++.h>
using namespace std;

int n, m, k, q, tmp, ans;
char s[110];

int main() {
	scanf("%d%d%d%d%s", &n, &m, &k, &q, s);
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') {
			if(tmp >= k)
				ans += q * tmp * tmp;
			tmp = 0;
		}
		else {
			tmp++;
			ans += m;
		}
	}
	if(tmp >= k)
		ans += q * tmp * tmp;
	printf("%d\n", ans);
	return 0;
}
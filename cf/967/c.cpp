#include <bits/stdc++.h>
using namespace std;

int lc1[100100], lc2[100100];
int n, m, c1, c2, v, q, n1, m1, n2, m2;
int main() {
	cin >> n >> m >> c2 >> c1 >> v;
	for(int i = 0; i < c2; ++i) 
		scanf("%d", &lc2[i]);
	for(int i = 0; i < c1; ++i) 
		scanf("%d", &lc1[i]);
	cin >> q;
	while(q--) {
		scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
		int d = abs(m1 - m2), dd = abs(n1 - n2);
		if(m1 > m2)
			m1 ^= m2 ^= m1 ^= m2;
		if(n1 == n2) {
			printf("%d\n", d);
			continue;
		}
		int ans = 0x3f3f3f3f;
		if(c1 && upper_bound(lc1, lc1 + c1, m1) != lc1 + c1 && *upper_bound(lc1, lc1 + c1, m1) < m2)
			ans = min(ans, d + (dd-1)/v + 1);
		if(c2 && upper_bound(lc2, lc2 + c2, m1) != lc2 + c2 && *upper_bound(lc2, lc2 + c2, m1) < m2)
			ans = min(ans, d + dd);
		if(c1 && upper_bound(lc1, lc1 + c1, m1) != lc1)
			ans = min(ans, d + (dd - 1)/v + 1 + 2 * (m1 - *((upper_bound(lc1, lc1 + c1, m1)) - 1)));
		if(c2 && upper_bound(lc2, lc2 + c2, m1) != lc2)
			ans = min(ans, d + dd + 2 * (m1 - *((upper_bound(lc2, lc2 + c2, m1)) - 1)));
		if(c1 && upper_bound(lc1, lc1 + c1, m2) != lc1 + c1)
			ans = min(ans, d + (dd - 1)/v + 1 + 2 * (*((upper_bound(lc1, lc1 + c1, m2))) - m2));
		if(c2 && upper_bound(lc2, lc2 + c2, m2) != lc2 + c2)
			ans = min(ans, d + dd + 2 * (*((upper_bound(lc2, lc2 + c2, m2))) - m2));
		printf("%d\n", ans);
	}
	return 0;
}
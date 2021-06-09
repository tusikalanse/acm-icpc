#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int b[N], g[N], n, m, mxb, mng = 1e9, posmx2b, posmxb;
long long ans;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		mxb = max(mxb, b[i]);
	}
	posmxb = 1;
	posmx2b = 2;
	if(b[1] < b[2])
		swap(posmxb, posmx2b);
	for(int i = 3; i <= n; ++i) {
		if(b[i] > b[posmx2b]) {
			posmx2b = i;
			if(b[posmxb] < b[posmx2b])
				swap(posmxb, posmx2b);
		}
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &g[i]);
		mng = min(mng, g[i]);
	}
	if(mng < mxb) {
		puts("-1");
		return 0;
	}
	for(int i = 1; i <= m; ++i) 
		ans += g[i];
	for(int i = 1; i <= n; ++i) {
		if(i == posmxb) {
			//ans += b[i];
		}
		else if(i == posmx2b) {
			//ans += 1LL * b[i] * (m - 1);
		}
		else
			ans += 1LL * b[i] * m;
	}
	if(mng == mxb)
		ans += 1LL * b[posmx2b] * m;
	else {
		ans += b[posmxb];
		ans += 1LL * b[posmx2b] * (m - 1);
	}
	printf("%lld\n", ans);
	return 0;
}
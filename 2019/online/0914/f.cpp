#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, a[N], k, lim[2], l, r, kk;
long long tot;

int main() {
	while(~scanf("%d%d", &n, &k)) {
		tot = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			tot += a[i];
		}
		sort(a + 1, a + n + 1);
		if(a[1] == a[n]) {
			puts("0");
			continue;
		}
		lim[0] = (tot - 1) / n + 1;
		lim[1] = tot / n;
		kk = k;
		for(int i = n; i; --i) {
			if(a[i] <= lim[0]) break;
			int tar = max(lim[0], a[i - 1]);
			kk -= (n - i + 1) * (a[i] - tar);
			if(kk < 0) {
				kk += (n - i + 1) * (a[i] - tar);
				r = a[i] - (kk / (n - i + 1)); 
				kk -= (n - i + 1) * (a[i] - tar);
				break;
			}
			if(a[i - 1] <= lim[0]) break;
		}
		if(kk >= 0) r = lim[0];
		kk = k;
		for(int i = 1; i <= n; ++i) {
			if(a[i] >= lim[1]) break;
			int tar = min(lim[1], a[i + 1]);
			kk -= i * (tar - a[i]);
			if(kk < 0) {
				kk += i * (tar - a[i]);
				l = a[i] + (kk / i); 
				kk -= i * (tar - a[i]);
				break;
			}
			if(a[i + 1] >= lim[1]) break;
		}
		if(kk >= 0) l = lim[1];
		// cout << "l, r = " << l << " " << r << endl;
		printf("%d\n", r - l);
	}
	return 0;
}
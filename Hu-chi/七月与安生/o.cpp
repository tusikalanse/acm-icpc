#include <bits/stdc++.h>
using namespace std;

int l[6], r[6], n;

bool check(int v, int a, int b) {
	for(int i = a; i <= b; ++i)
		if(l[i] > v || r[i] < v)
			return false;
	return true;
}

int cnt(int t) {
	int ans = 0;
	while(t) {
		ans += t & 1;
		t >>= 1;
	}
	return ans;
}

int main() {
	cin >> n;
	double div = 1, ans = 0;
	int mmax = 0;
	for(int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		mmax = max(mmax, r[i]);
		div /= (r[i] - l[i] + 1);
	}
	for(int v = 1; v <= mmax; ++v) {
		for(int p = 1; p < (1 << n); ++p) {
			if(cnt(p) != 1) {
				int s = p;
				double tmp = 1;
				for(int i = 0; i < n; ++i) {
					if((1 << i) & s) {
						tmp *= check(v, i, i);
					}
					else {
						tmp *= max(min(r[i] - l[i] + 1, v - l[i]), 0);
					}
				}
				ans += tmp * v;
			}
			for(int big = 0; big < n; ++big) {
				if((1 << big) & p)
					continue;
				int s = p | (1 << big);
				double tmp = 1;
				for(int i = 0; i < n; ++i) {
					if((1 << i) & s) {
						if(i != big) {
							tmp *= check(v, i, i);
						}
						else {
							tmp *= max(min(r[i] - v, 1 + r[i] - l[i]), 0);
						}
					}
					else {
						tmp *= max(min(1 + r[i] - l[i], v - l[i]), 0);
					}
				}
				ans += tmp * v;
			}
		}
	}
	ans *= div;
	printf("%.10f\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int n, p;
int a[100010];
int l = 0, r = 0, mmax = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		r += a[i];
		r %= p;
	}
	l = a[0] % p;
	r -= a[0];
	r = (r % p + p) % p;
	mmax = l + r;
	for(int i = 1; i < n - 1; ++i) {
		l += a[i];
		l %= p;
		r = ((r - a[i]) % p + p) % p;
		mmax = max(mmax, l + r);
	}
	cout << mmax << endl;

	return 0;
}
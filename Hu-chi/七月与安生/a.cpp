#include <bits/stdc++.h>
using namespace std;

inline double qp(double a, int n) {
	double ans = 1;
	while(n) {
		if(n & 1)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}


int main() {
	double n, m;
	cin >> n >> m;
	double ans = n;
	for(int i = 1; i < n; ++i)
		ans -= qp(i/n, m);
	cout << ans << endl;


	return 0;
}
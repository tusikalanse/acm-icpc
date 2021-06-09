#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	cout << 1LL*(6*n-1)*k << endl;
	for(int i = 1; i <= n; ++i) {
		cout << 1LL*(6*i-5)*k << ' ' << 1LL*(6*i-4)*k << ' ' << 1LL*(6*i-3)*k << ' ' << 1LL*(6*i-1)*k << endl;
	}
	return 0;
}
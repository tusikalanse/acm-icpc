#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	if(k > (n - 1) * (m - 1))
		cout << -1 << endl;
	else
		cout << n + m - 2 << endl;
	return 0;
}
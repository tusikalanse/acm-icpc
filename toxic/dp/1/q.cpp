#include <bits/stdc++.h>
using namespace std;

set<long long> r[100];
long long f[100], n;

int main() {
	r[0].insert(0);
	for(int i = 0; i < 80; ++i) {
		for(auto &it: r[i]) {
			r[i + 1].insert(it + 1);
			r[i + 1].insert(it + 5);
			r[i + 1].insert(it + 10);
			r[i + 1].insert(it + 50);
		}
		f[i + 1] = r[i + 1].size();
	}
	cin >> n;
	if(n <= 30) {
		cout << f[n] << endl;
		return 0;
	}
	cout << 49LL * n - 247 << endl;
	return 0;
}
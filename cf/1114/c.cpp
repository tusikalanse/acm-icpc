#include <bits/stdc++.h>
using namespace std;

long long n, b, ans = 1e18;
vector<pair<long long, long long>> fac;

long long foo(long long n, long long x, long long cnt) {
	long long res = 0;
	while(n) {
		res += n / x;
		n /= x;
	}
	return res / cnt;
}

int main() {
	cin >> n >> b;
	long long i = 2, tmp;
	while(i * i <= b) {
		if(b % i == 0) {
			tmp = 0;
			while(b % i == 0) {
				tmp++;
				b /= i;
			}
			fac.push_back(make_pair(i, tmp));
		}
		i++;
	}
	if(b != 1) {
		fac.push_back(make_pair(b, 1));
	}
	for(auto &i: fac) {
		ans = min(ans, foo(n, i.first, i.second));
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> fac(int x) {
	int i = 2;
	vector<int> res;
	while(i * i <= x) {
		if(x % i == 0) {
			res.push_back(i);
			while(x % i == 0) x /= i;
		}
		i++;
	}
	if(x != 1) 
		res.push_back(x);
	return res;
}

const int mod = 1e9 + 7;
int x;
long long n, ans = 1;

int qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int gao(int pm, long long n) {
	long long tmp = 1, res = 1;
	while(n) {
		long long now = n - n / pm;
		now %= (mod - 1);
		res = (res * qp(tmp, now)) % mod;
		tmp *= pm;
		tmp %= mod;
		n /= pm;
	}
	return res;
}

int main() {
	cin >> x >> n;
	for(auto i : fac(x))
		ans = (ans * gao(i, n)) % mod;
	cout << ans << endl;
	return 0;
}
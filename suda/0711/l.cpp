#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<char, int> s;
ll cnt[4];

int main() {
	s['A'] = 0;
	s['T'] = 1;
	s['G'] = 2;
	s['C'] = 3;
	string t;
	ll n;
	cin >> n;
	cin >> t;
	for(int i = 0; i < n; ++i)
		cnt[s[t[i]]]++;
	ll mod = 1e9 + 7;
	ll a = 0, mmax = -1;
	for(int i = 0; i < 4; ++i) {
		if(cnt[i] == mmax)
			a++;
		else if(cnt[i] > mmax) {
			mmax = cnt[i];
			a = 1;
		}
	}
	ll ans = 1;
	while(n) {
		if(n & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	printf("%lld\n", ans);
	return 0;
}
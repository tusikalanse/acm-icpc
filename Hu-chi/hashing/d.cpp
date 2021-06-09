#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int kind = 257, mod = 1e9 + 7;
string s[300010], t;
set<LL> vis;
LL f[600010] = {1};


void init() {
    for(int i = 1; i < 600003 ; ++i){
        f[i] = f[i - 1] * 257 % mod;
    }
}


LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1) 
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

LL HASH(const string &s) {
	LL ans = 0;
	for(LL i = 0; i < s.size(); ++i) {
		ans = ans * kind + s[i];
		ans %= mod;
	}
	return ans;
}

LL n, m;

bool judge() {
	char ch;
	LL l = t.size(), tmp = 1, hs = HASH(t);
	for(int i = 0; i < l; ++i) {
		for(int c = 'a'; c <= 'c'; c++){
	        if(t[i] == c) 
	           	continue;
	        if(vis.find((((c - t[i]) * f[l - i - 1] + hs) % mod + mod) % mod) != vis.end()) 
	           	return 1;
	    }
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> n >> m;
	for(LL i = 0; i < n; ++i) {
		cin >> s[i];
		vis.insert(HASH(s[i]));
	}
	for(LL i = 0; i < m; ++i) {
		cin >> t;
		if(judge()) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
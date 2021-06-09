#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cmath>
#include <map>
#include <string>
#include <set>
using namespace std;

inline int getint() {
	char ch;
	int flag = 1, res = 0;
	ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-')
			flag *= -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0') {
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res * flag;
}


const int MAXN = 5e5 + 10, mod = 1e9;

long long qp(long long a, long long b) {
	long long res = 1;
	while(b) {
		if(b & 1) 
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}



int sum[35][MAXN];
int a[MAXN];

map<int, int> ansd;

int main() {
	int T, n, m, p;
	set<int> setp;
	T = getint();
	while(T--) {
		setp.clear();
		n = getint();
		m = getint();
		for(register int i = 1; i <= n; ++i)
			a[i] = getint();
		sort(a + 1, a + n + 1);
		for(register int i = 1; i <= 31; ++i) {
			for(int j = 1; j <= n; ++j) {
				sum[i][j] = sum[i][j-1] + a[j]/i;
				sum[i][j] %= mod;
			}
		}
		long long res = 0;
		for(register int tt = 1; tt <= m; ++tt) {
			p = getint();
			if(setp.find(p) != setp.end()) {
				res = (res + 1LL * tt * ansd[p] % mod) % mod;
				continue;
			}
			setp.insert(p);
            long long ans = 0, fck = 1;
            int fi = 1, la;
			for(register int i = 1; i <= 31; ++i) {
				if(fi > n)
					break;
				if(fck * p > 1e9) {
					ans += sum[i][n] - sum[i][fi - 1];
					ans = (ans + mod) % mod;
					break;
				}
				la = upper_bound(a + 1, a + n + 1, fck * p) - a - 1;
				ans += sum[i][la] - sum[i][fi - 1];
				fi = la + 1;
				ans = ans % mod;
				fck *= p;
			}
			ansd[p] = ans;
			res = (res + 1LL * tt * ans % mod) % mod;
		}
		printf("%lld\n", (res+mod)%mod);
	}
	return 0;
}
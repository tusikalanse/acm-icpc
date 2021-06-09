#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 3e5, mod = 998244353, g = 3;
typedef long long LL;

LL ans[MAXN];

LL a[MAXN], b[MAXN];
int n, m, N, tmp, tot, inv;
int rev[MAXN];
void get_rev(int bit) {
	for(int i = 0; i < (1 << bit); ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
	}
}

LL qp(LL a,LL n) {
    LL ans=1;
    while(n) {
    	if(n & 1)
    		ans = ans * a % mod;
    	a = a * a % mod;
    	n >>= 1;
    }
    return ans;
}

void NTT(LL a[], int N, int on) {
	for(int i = 0; i < N; ++i) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int i = 2, mid = 1; i <= N; i <<= 1, mid <<= 1) {
        LL wn = qp(g, (mod - 1) / i);
        if(on == -1) wn = qp(wn, mod - 2);
        for(int j = 0; j < N; j += i) {
            LL w = 1;
            for(int k = j; k < j + mid; ++k) {
                LL u = a[k], v = w * a[k + mid] % mod;
          		a[k] = (u + v) % mod;
          		a[k + mid] = (u - v) % mod;
                w = w * wn % mod;
            }
        }
    }
    if(on == -1) {
        for(int i = 0; i < N; ++i)
            a[i] = a[i] * inv % mod;
    }
}

map<int, vector<int>> mmpa, mmpb;

void brute_force(vector<int> &a, vector<int> &b) {
	for(auto &it: a) 
		for(auto &ti: b) {
			ans[it + ti] = (ans[it + ti] + 1LL * it * ti) % mod;
		}
}

void fafata(vector<int> &aa, vector<int> &bb) {
	for(int i = 0; i < N; ++i) {
		a[i] = b[i] = 0;
	}
	for(auto &it: aa)
		a[it] = it;
	for(auto &it: bb)
		b[it] = it;
	NTT(a, N, 1);
	NTT(b, N, 1);
	for(int i = 0; i < N; ++i)
		a[i] = a[i] * b[i] % mod;
	NTT(a, N, -1);
	for(int i = 0; i < tot; ++i) {
		ans[i] = (ans[i] + a[i]) % mod;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	tot = n + m + 1;
	N = n + m + 1;
	int bit = 1;
	while((1 << bit) < N) bit++;
	N = 1 << bit;
	inv = qp(N, mod - 2);
	get_rev(bit);
	for(int i = 0; i <= n; ++i) {
		scanf("%d", &tmp);
		mmpa[tmp].push_back(i);
	}
	for(int i = 0; i <= m; ++i) {
		scanf("%d", &tmp);
		mmpb[tmp].push_back(i);
	}
	for(auto it = mmpa.begin(); it != mmpa.end(); ++it) {
		if(mmpb.find(it -> first) == mmpb.end()) continue;
		int x = (it -> second).size(), y = mmpb[it->first].size();
		if(1LL * x * y < 15000000)
			brute_force(it->second, mmpb[it->first]);
		else
			fafata(it->second, mmpb[it->first]);
	}
	for(int i = 0; i < tot; ++i)
		printf("%lld%c", (ans[i] + mod) % mod, " \n"[i == tot - 1]);
	return 0;
}
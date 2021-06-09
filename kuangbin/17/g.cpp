#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#include <map>
using namespace std;

const int MAXN = 110;
const int KIND = 50;

map<char, int> mp;
int n, m, p;


struct Mat {
	int n;
	int a[MAXN][MAXN];
	Mat(int _n) {
		n = _n;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				a[i][j] = 0;
	}
};

struct AC_automata {
	int root, L;
	int nxt[MAXN][KIND], fail[MAXN], end[MAXN];
	void init() {
		L = 0;
		root = newnode();
	}
	int newnode() {
		for(int i = 0; i < KIND; ++i)
			nxt[L][i] = -1;
		fail[L] = -1;
		end[L] = 0;
		return L++;
	}
	void insert(char *s) {
		int p = root;
		for(int i = 0; s[i]; ++i) {
			if(nxt[p][mp[s[i]]] == -1)
				nxt[p][mp[s[i]]] = newnode();
			p = nxt[p][mp[s[i]]];
		}
		end[p] = 1;
	}
	void getfail() {
		queue<int> Q;
		fail[root] = root;
		for(int i = 0; i < KIND; ++i) {
			if(nxt[root][i] == -1)
				nxt[root][i] = root;
			else {
				fail[nxt[root][i]] = root;
				Q.push(nxt[root][i]);
			}
		}
		while(!Q.empty()) {
			int tmp = Q.front();
			Q.pop();
			if(end[fail[tmp]] == 1)
				end[tmp] = 1;
			for(int i = 0; i < KIND; ++i) {
				if(nxt[tmp][i] == -1)
					nxt[tmp][i] = nxt[fail[tmp]][i];
				else {
					fail[nxt[tmp][i]] = nxt[fail[tmp]][i];
					Q.push(nxt[tmp][i]);
				}
			}
		}
	}
	Mat getmatix() {
		Mat res(L);
		for(int i = 0; i < L; ++i) {
			if(end[i] == 0) {
				for(int j = 0; j < n; ++j) {
					if(end[nxt[i][j]] == 0)
						res.a[i][nxt[i][j]]++;
				}
			}
		}
		return res;
	}
}AC;

struct BigInt {
    const static int mod = 10000;
    const static int DLEN = 4;
    int a[600], len;
    BigInt() {
        memset(a, 0, sizeof(a));
        len = 1;
    }
    BigInt(int v) {
        memset(a, 0, sizeof(a));
        len = 0;
        do {
            a[len++] = v % mod;
            v /= mod;
        } while(v);
    }
    BigInt(const char s[]) {
        memset(a, 0, sizeof(a));
        int L = strlen(s);
        len = L / DLEN;
        if(L % DLEN) len++;
        int index = 0;
        for(int i = L - 1;i >= 0;i -= DLEN) {
            int t = 0;
            int k = i - DLEN + 1;
            if(k < 0) k = 0;
            for(int j = k;j <= i;j++)
                t = t * 10 + s[j] - '0';
            a[index++] = t;
        }
    }
    BigInt operator +(const BigInt &b) const {
        BigInt res;
        res.len = max(len, b.len);
        for(int i = 0;i <= res.len;i++)
            res.a[i] = 0;
        for(int i = 0;i < res.len;i++) {
            res.a[i] += ((i < len) ? a[i] : 0) + ((i < b.len) ? b.a[i] : 0);
            res.a[i + 1] += res.a[i] / mod;
            res.a[i] %= mod;
        }
        if(res.a[res.len] > 0) res.len++;
        return res;
    }
    BigInt operator *(const BigInt &b) const {
        BigInt res;
        for(int i = 0; i < len;i++) {
            int up = 0;
            for(int j = 0;j < b.len;j++) {
                int temp = a[i] * b.a[j] + res.a[i + j] + up;
                res.a[i + j] = temp % mod;
                up = temp / mod;
            }
            if(up != 0)
                res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 && res.len > 1)res.len--;
        return res;
    }
    void output() {
        printf("%d",a[len - 1]);
        for(int i = len - 2;i >= 0 ;i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};

BigInt dp[2][110];
char s[60];

int main() {
	while(~scanf("%d %d %d", &n, &m, &p)) {
		AC.init();
		mp.clear();
		gets(s);
		gets(s);
		for(int i = 0; s[i]; ++i) {
			mp[s[i]] = i;
		}
		while(p--) {
			gets(s);
			AC.insert(s);
		}
		AC.getfail();
		Mat res = AC.getmatix();
		int now = 0;
		dp[now][0] = 1;
		for(int i = 1; i < res.n; ++i)
			dp[now][i] = 0;
		for(int i = 0; i < m; ++i) {
			now ^= 1;
			for(int j = 0; j < res.n; ++j)
				dp[now][j] = 0;
			for(int j = 0; j < res.n; ++j) {
				for(int k = 0; k < res.n; ++k) {
					if(res.a[j][k] > 0) 
						dp[now][k] = dp[now][k] + dp[now ^ 1][j] * res.a[j][k];
				}
			}
		}
		BigInt ans = 0;
		for(int i = 0; i < res.n; ++i) {
			ans = ans + dp[now][i];
		} 
		ans.output();
	}
	return 0;
}
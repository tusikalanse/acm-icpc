#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int MAXN = 110;
const int KIND = 26;
const int mod = 20090717;

struct AC_automata {
	int dp[26][MAXN][1 << 10], bit_cnt[1 << 10];
	int nxt[MAXN][KIND], fail[MAXN], end[MAXN];
	int L, root;
	int newnode() {
		for(int i = 0; i < KIND; ++i)
			nxt[L][i] = -1;
		fail[L] = -1;
		end[L] = 0;
		return L++;
	}
	void init() {
		L = 0;
		root = newnode();
	}
	void insert(char s[], int c) {
		int p = root;
		for(int i = 0; s[i]; ++i) {
			if(nxt[p][s[i] - 'a'] == -1) 
				nxt[p][s[i] - 'a'] = newnode();
			p = nxt[p][s[i] - 'a'];
		}
		end[p] |= (1 << c);
	}
	void getfail() {
		queue<int> Q;
		fail[root] = root;
		for(int i = 0; i < KIND; ++i) {
			if(nxt[root][i] == -1) {
				nxt[root][i] = root;
			}
			else {
				fail[nxt[root][i]] = root;
				Q.push(nxt[root][i]);
			}
		}
		while(!Q.empty()) {
			int tmp = Q.front();
			Q.pop();
			end[tmp] |= end[fail[tmp]];
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
	void pre() {
		bit_cnt[0] = 0;
		for(int i = 1; i < (1 << 10); ++i)
			bit_cnt[i] = bit_cnt[i >> 1] + (i & 1);
	}
	int DP(int n, int m, int k) {
		for(int i = 0; i <= n; ++i) 
			for(int j = 0; j < L; ++j) 
				for(int k = 0; k < (1 << m); ++k)
					dp[i][j][k] = 0;
		dp[0][0][0] = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < L; ++j) {
				for(int p = 0; p < (1 << m); ++p) {
					if(dp[i][j][p] == 0)
						continue;
					for(int k = 0; k < KIND; ++k) {
						int u = nxt[j][k];
						(dp[i + 1][u][end[u] | p] += dp[i][j][p]) %= mod;
					}
				}
			}
		}
		int ans = 0;
		for(int p = 0; p < (1 << m); ++p) {
			if(bit_cnt[p] >= k)
				for(int j = 0; j < L; ++j)
					(ans += dp[n][j][p]) %= mod;
		}
		return ans;
	}
}AC;

char s[20];


int main() {
	AC.pre();
	int n, m, k;
	while(~scanf("%d %d %d", &n, &m, &k) && (n || m || k)) {
		AC.init();
		for(int i = 0; i < m; ++i) {
			scanf("%s", s);
			AC.insert(s, i);
		}
		AC.getfail();
		printf("%d\n", AC.DP(n, m, k));
	}
	return 0;
}
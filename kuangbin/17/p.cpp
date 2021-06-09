#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;


const int MAXN = 510;
const int KIND = 55;
const double INF = 1e20;

struct AC_automata {
	double dp[KIND][MAXN];
	double pt[KIND][2];
	double g[KIND][KIND];
	int L, root;
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
	void insert(int s[]) {
		int p = root;
		for(int i = 0; s[i]; ++i) {
			if(nxt[p][s[i]] == -1)
				nxt[p][s[i]] = newnode();
			p = nxt[p][s[i]];
		}
		end[p] = 1;
	}
	void getfail(int n) {
		queue<int> Q;
		fail[root] = root;
		for(int i = 1; i <= n; ++i) {
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
			for(int i = 1; i <= n; ++i) {
				if(nxt[tmp][i] == -1) 
					nxt[tmp][i] = nxt[fail[tmp]][i];
				else {
					fail[nxt[tmp][i]] = nxt[fail[tmp]][i];
					Q.push(nxt[tmp][i]);
				}
			}
		}
	}
	void pre(int n) {
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j < L; ++j) 
				dp[i][j] = INF;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= i; ++j) {
				g[i][j] = g[j][i] = hypot(pt[i][0] - pt[j][0], pt[i][1] - pt[j][1]);
			}
	}
	void DP(int n) {
		pre(n);
		double ans = INF;
		dp[1][nxt[root][1]] = 0;
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j < L; ++j) {
				if(dp[i][j] < INF) {
					for(int k = i + 1; k <= n; ++k) {
						if(end[nxt[j][k]])
							continue;
						dp[k][nxt[j][k]] = min(dp[k][nxt[j][k]], dp[i][j] + g[i][k]);
					}
				}
			}
		}
		for(int i = 0; i < L; ++i) {
			ans = min(ans, dp[n][i]);
		}
		if(ans == INF)
			puts("Can not be reached!");
		else 
			printf("%.2lf\n", ans);
	}
}AC;

int main() {
	int n, m, k, a[12];
	while(~scanf("%d %d", &n, &m) && n) {
		AC.init();
		for(int i = 1; i <= n; ++i)
			scanf("%lf %lf", &AC.pt[i][0], &AC.pt[i][1]);
		for(int i = 0; i < m; ++i) {
			scanf("%d", &k);
			for(int j = 0; j < k; ++j)
				scanf("%d", &a[j]);
			a[k] = 0;
			AC.insert(a);
		}
		AC.getfail(n);
		AC.DP(n);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8;
int dp[110][110][11][11], n[2], k[2];
int vis[110][110][11][11];

int f(int n1, int n2, int l1, int l2) {
	if(vis[n1][n2][l1][l2])
		return dp[n1][n2][l1][l2];
	vis[n1][n2][l1][l2] = 1;
	if(n1 == n[0] && n2 == n[1])
		return dp[n[0]][n[1]][l1][l2] = 1;
	if(l1 < k[0] && n1 < n[0])
		dp[n1][n2][l1][l2] = (dp[n1][n2][l1][l2] + f(n1 + 1, n2, l1 + 1, 0)) % mod;
	if(l2 < k[1] && n2 < n[1])
		dp[n1][n2][l1][l2] = (dp[n1][n2][l1][l2] + f(n1, n2 + 1, 0, l2 + 1)) % mod;
	return dp[n1][n2][l1][l2];
}



int main() {
	cin >> n[0] >> n[1] >> k[0] >> k[1];
	cout << f(0, 0, 0, 0) << endl;
	return 0;
}
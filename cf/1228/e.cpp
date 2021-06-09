#include <bits/stdc++.h>
using namespace std;

int n, K;
const int mod = 1e9 + 7;
int dp[255][255], fac[255], invfac[255];

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

int QP[2][255];

void init() {
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 250; ++i)
        fac[i] = 1LL * fac[i - 1] * i % mod;
    invfac[250] = qp(fac[250], mod - 2);
    for(int i = 249; ~i; --i)
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
    return 1LL * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

int main() {
    init();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    cin >> n >> K;
    for(int i = 0; i <= 250; ++i) {
        QP[0][i] = qp(K, i);
        QP[1][i] = qp(K - 1, i);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            for(int k = max(1, j); k <= n; ++k) {
                if(k == j) 
                    dp[i + 1][k] = (dp[i + 1][k] + 1LL * dp[i][j] * (((QP[0][j] - QP[1][j]) % mod + mod) % mod) % mod * QP[1][n - j] % mod) % mod;
                else
                    dp[i + 1][k] = (dp[i + 1][k] + 1LL * dp[i][j] * C(n - j, k - j) % mod * QP[0][j] % mod * QP[1][n - k] % mod) % mod;
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
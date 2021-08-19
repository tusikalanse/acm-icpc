/*
 * @Author: tusikalanse
 * @Date: 2021-08-19 16:44:32
 * @LastEditTime: 2021-08-19 17:26:56
 * @LastEditors: tusikalanse
 * @Description: prime test & dfs
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
//-------------------end head--------------

const int N = 1e7 + 10;

int prime[N];
bool notprime[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

bool isprime(LL x) {
    if (x < N)
        return !notprime[x];
    for (int i = 1; i <= prime[0] && 1LL * prime[i] * prime[i] <= x; ++i) {
        if (x % prime[i] == 0)
            return false;
    }
    return true;
}

int number[10];
int temp[10];
int n = 10;

LL gao() {
    if (temp[0] == 0)
        return 0;
    LL val = 0;
    for (int i = 0; i < n; ++i) {
        val = val * 10 + temp[i];
    }
    return val * isprime(val);
}

LL dfs(int num, int now, int digit, int pos) {
    LL ans = 0;
    if (pos == n) {
        for (int i = 0; i < n - digit; ++i) {
            number[i] = num;
        }
        memcpy(temp, number, sizeof(temp));
        sort(temp, temp + n);
        do {
            ans += gao();
        } while (next_permutation(temp, temp + n));
        return ans;
    }
    for (int i = now; i < 10; ++i) {
        if (i == num)
            continue;
        number[pos] = i;
        ans += dfs(num, i, digit, pos + 1);
    }
    return ans;
}

LL get(int num, int digit) {
    LL ans = 0;
    ans += dfs(num, 0, digit, n - digit);
    return ans;
}

int main() {
    getprime();
    LL ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 1;; ++j) {
            if (LL x = get(i, j); x) {
                ans += x;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
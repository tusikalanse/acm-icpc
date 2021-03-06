/*
 * @Author: tusikalanse
 * @Date: 2021-08-19 09:17:51
 * @LastEditTime: 2021-08-19 09:29:02
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
const int N = 1e8 + 10;

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
    if (1LL * prime[prime[0]] * prime[prime[0]] < x) {
        LL i = prime[prime[0]] + 1;
        while (i * i <= x) {
            if (x % i == 0)
                return false;
            i++;
        }
    }
    return true;
}

int ans = 0;

int a[10];
vector<char> v;

void dfs(int now, int pos) {
    if (pos == 9) {
        ans++;
        return;
    }
    int val = 0;
    for (int i = pos; i < 9; ++i) {
        val = val * 10 + v[i] - '0';
        if (isprime(val)) {
            if (now == 0 || val % 10 > a[now - 1] % 10) {
                a[now] = val;
                dfs(now + 1, i + 1);
            }
        }
    }
}

int main() {
    getprime();
    for (char i = '1'; i <= '9'; ++i) {
        v.push_back(i);
    }
    do {
        dfs(0, 0);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}
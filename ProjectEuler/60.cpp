/*
 * @Author: tusikalanse
 * @Date: 2021-07-12 14:57:00
 * @LastEditTime: 2021-07-12 19:32:46
 * @LastEditors: tusikalanse
 * @Description: 
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

const int N = 1e4 + 10;

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
    if (x < N) return !notprime[x];
    for (int i = 1; i <= prime[0]; ++i) {
        if (x % prime[i] == 0) return false;
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

int p[8];

LL concatenate(int x, int y) {
    string s = to_string(x) + to_string(y);
    return stoll(s);
}

void dfs(int now, int pos) {
    if (now == 5) {
        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            cout << p[i] << " ";
            ans += p[i];
        }
        cout << ans << endl;
        exit(0);
    }
    for (int i = pos; i <= prime[0]; ++i) {
        bool flag = true;
        for (int j = 0; j < now; ++j) {
            flag &= isprime(concatenate(p[j], prime[i]));
            flag &= isprime(concatenate(prime[i], p[j]));
        }
        if (flag) {
            p[now] = prime[i];
            dfs(now + 1, i + 1);
        }
    }
}

int main() {
    getprime();
    dfs(0, 2);
    return 0;
}

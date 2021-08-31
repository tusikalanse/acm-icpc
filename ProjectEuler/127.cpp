/*
 * @Author: tusikalanse
 * @Date: 2021-08-31 09:25:30
 * @LastEditTime: 2021-08-31 12:32:06
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

const int N = 12e4 + 10;

bool notprime[N];
int prime[N];
int rad[N];

void getprime() {
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    rad[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            rad[i] = i;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                rad[i * prime[j]] = rad[i];
                break;
            }
            else {
                rad[i * prime[j]] = rad[i] * prime[j];
            }
        }
    }
}

int n = 120000;
LL ans = 0;
int cnt = 0;

struct node {
    int rad, n;
    bool operator<(const node &rhs) const {
        return make_pair(rad, n) < make_pair(rhs.rad, rhs.n);
    }
};

int main() {
    getprime();
    set<node> s;
    s.insert({1, 1});
    // s.insert({2, 2});
    for (int c = 3; c < n; ++c) {
        for (auto x: s) {
            if (x.rad * rad[c] >= c) break;
            int a = x.n, b = c - a;
            if (gcd(a, b) != 1) continue;
            if (1LL * rad[a] * rad[b] * rad[c] < c)
            {
                cnt++;
                ans += c;
            }      
        }
        if (c % 2 == 0) {
            s.insert({rad[c / 2], c / 2});
        }
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}
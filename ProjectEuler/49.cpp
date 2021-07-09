/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 21:19:48
 * @LastEditTime: 2021-07-09 21:23:19
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

bool is_permutation(int x, int y) {
    vector<int> a, b;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    while (y) {
        b.push_back(y % 10);
        y /= 10;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    getprime();
    for (int i = 1001; i < 10000; ++i) {
        if (notprime[i]) continue;
        for (int d = 1; i + d + d < 10000; ++d) {
            if (notprime[i + d]) continue;
            if (!is_permutation(i, i + d)) continue;
            if (notprime[i + d + d]) continue;
            if (!is_permutation(i, i + d + d)) continue;
            cout << i << " " << i + d << " " << i + d + d << endl;
        }
    }
    return 0;
}

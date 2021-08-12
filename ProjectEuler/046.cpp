/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 08:54:35
 * @LastEditTime: 2021-07-09 21:02:11
 * @LastEditors: tusikalanse
 * @Description:
 * @FilePath: /ProjectEuler/46.cpp
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

bool is_square(int x) {
    int d = sqrt(x + 0.5);
    return d * d == x;
}

int main() {
    getprime();
    for (int x = 9;; x += 2) {
        if (!notprime[x])
            continue;
        int flag = 0;
        for (int j = 2; prime[j] < x; ++j) {
            if (is_square((x - prime[j]) / 2)) {
                flag = 1;
                cout << x << " = " << prime[j] << " + 2 * " << int(sqrt((x - prime[j]) / 2 + 0.5)) << "^2" << endl;
                break;
            }
        }
        if (flag)
            continue;
        cout << x << endl;
        break;
    }
    return 0;
}

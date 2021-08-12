/*
 * @Author: tusikalanse
 * @Date: 2021-07-10 09:23:24
 * @LastEditTime: 2021-07-10 09:57:43
 * @LastEditors: tusikalanse
 * @Description: euler sieve + bitmask
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

const int N = 1e6 + 10;

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

int vis[N];

int ten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 100000000, 1000000000};

int get_val(int n, int mask) {
    int res = 0, cnt = 0;
    while (n) {
        if (mask & 1)
            res += (n % 10) * ten[cnt];
        n /= 10;
        mask >>= 1;
        cnt++;
    }
    return res;
}

int set_val(int n, int mask, int val) {
    int res = 0, m = mask, cnt = 0;
    while (m) {
        if (m & 1)
            res += ten[cnt];
        cnt++;
        m >>= 1;
    }
    return res * val + n - get_val(n, mask);
}

int main() {
    getprime();
    for (int i = 1; i <= prime[0]; ++i) {
        int d = to_string(prime[i]).size();
        for (int mask = 1; mask < (1 << d) - 1; ++mask) {
            int cnt = 0;
            for (int digit = 0; digit <= 9; ++digit) {
                if (digit == 0 && (mask >> d - 1) == 1)
                    continue;
                cnt += !notprime[set_val(prime[i], mask, digit)];
            }
            if (cnt == 8) {
                cout << prime[i] << endl;
                cout << mask << endl;
                for (int digit = 0; digit <= 9; ++digit) {
                    if (digit == 0 && (mask >> d - 1) == 1)
                        continue;
                    if (!notprime[set_val(prime[i], mask, digit)]) {
                        cout << set_val(prime[i], mask, digit) << " ";
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}

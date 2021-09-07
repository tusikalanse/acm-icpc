/*
 * @Author: tusikalanse
 * @Date: 2021-09-03 20:45:07
 * @LastEditTime: 2021-09-07 09:16:46
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

const int N = 1e6 + 10;

bool notprime[N];
int prime[N];

void getprime() {
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) 
                break;
        }
    }
}

int get(int n) {
    int x = 1, digit = 1;
    while (x) {
        x = x * 10 + 1;
        x %= n;
        digit++;
    }
    return digit;
}

int main() {
    int cnt = 0, sum = 0;
    getprime();
    for (int i = 9; i < N; i += 2) {
        if (i % 5 == 0) continue;
        if (!notprime[i]) continue;
        if ((i - 1) % get(i) == 0) {
            sum += i;
            cnt++;
            if (cnt == 25) {
                cout << i << endl;
                break;
            }
        }
    }
    cout << cnt << " " << sum  << endl;
    return 0;
}
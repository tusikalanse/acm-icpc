/*
 * @Author: tusikalanse
 * @Date: 2021-07-18 23:13:58
 * @LastEditTime: 2021-07-18 23:26:23
 * @LastEditors: tusikalanse
 * @Description: Integer partition
 * @FilePath: /ProjectEuler/76.cpp
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

const int N = 1010;
int f[N], w[N];

void init(){
    int cnt = 0;
	for (int i = 1; ; i++) {
        if (1ll * i * (3 * i - 1) / 2 < N) w[++cnt] = i * (3 * i - 1) / 2; else break;
        if (1ll * i * (3 * i + 1) / 2 < N) w[++cnt] = i * (3 * i + 1) / 2; else break;
    }
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 0;
        for (int j = 1; j <= cnt && w[j] <= i; j++) {
            int k = (j + 1) / 2;
            if (k & 1) f[i] = f[i] + f[i - w[j]];
            else f[i] = f[i] - f[i - w[j]];
        }
    }
}

int main() {
    init();
    for (int i = 1; i <= 100; ++i)
        cout << f[i] << " ";
    cout << endl;
    cout << f[100] - 1 << endl;
    return 0;
}

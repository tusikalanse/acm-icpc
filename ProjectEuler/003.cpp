/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 19:26:35
 * @LastEditTime: 2021-06-09 19:29:21
 * @LastEditors: tusikalanse
 * @Description: Largest prime factor
 * @FilePath: /undefined/mnt/e/algo/ProjectEuler/3.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const long long N = 600851475143;

long long gao(long long x) {
    long long ans = 0;
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            ans = max(ans, i);
        while (x % i == 0)
            x /= i;
    }
    if (x != 1)
        ans = max(ans, x);
    return ans;
}

int main() {
    cout << gao(N) << endl;
    return 0;
}
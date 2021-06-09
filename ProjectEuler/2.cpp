/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 19:22:29
 * @LastEditTime: 2021-06-09 19:26:32
 * @LastEditors: tusikalanse
 * @Description: Even Fibonacci numbers
 * @FilePath: /undefined/mnt/e/algo/ProjectEuler/2.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 4000000;

int main() {
    int f1 = 1, f2 = 1, f3 = 2;
    long long ans = 0;
    while (f3 < N) {
        if (f3 % 2 == 0) ans += f3;
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    cout << ans << endl;
    return 0;
}
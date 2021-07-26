/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 19:11:39
 * @LastEditTime: 2021-06-09 19:22:24
 * @LastEditors: tusikalanse
 * @Description: Multiples of 3 and 5
 * @FilePath: /undefined/mnt/e/algo/ProjectEuler/1.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int gao(int val, int limit) {
    int cnt = limit / val;
    return val * cnt * (cnt + 1) / 2;
}

int main() {
    int ans = gao(3, 999) + gao(5, 999) - gao(15, 999);
    cout << ans << endl;
    return 0;
}
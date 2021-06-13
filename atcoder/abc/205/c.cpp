/*
 * @Author: tusikalanse
 * @Date: 2021-06-13 20:04:51
 * @LastEditTime: 2021-06-13 20:09:50
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/abc/205/c.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int a, b, c;

int main() {
    cin >> a >> b >> c;
    if (a >= 0 && b >= 0) {
        if (a > b)
            puts(">");
        else if (a < b)
            puts("<");
        else 
            puts("=");
    }
    else if (a < 0 && b < 0) {
        if (c % 2 == 0) {
            if (a < b)
                puts(">");
            else if (a > b)
                puts("<");
            else 
            puts("=");
        }
        else {
            if (a > b)
                puts(">");
            else if (a < b)
                puts("<");
            else 
                puts("=");
        }
    }
    else if (a < 0) {
        if (c % 2 == 0) {
            a = -a;
            if (a > b)
                puts(">");
            else if (a < b)
                puts("<");
            else 
                puts("=");
        }
        else
            puts("<");
    }
    else if (b < 0) {
        if (c % 2 == 0) {
            b = -b;
            if (a > b)
                puts(">");
            else if (a < b)
                puts("<");
            else 
                puts("=");
        }
        else
            puts(">");
    }

    return 0;
}

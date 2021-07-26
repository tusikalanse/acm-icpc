/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 19:32:43
 * @LastEditTime: 2021-06-09 19:36:35
 * @LastEditors: tusikalanse
 * @Description: Largest palindrome product
 * @FilePath: /undefined/mnt/e/algo/ProjectEuler/4.cpp
 */
#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(int x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; ++i) {
        for (int j = 100; j < 1000; ++j) {
            if (ispalindrome(i * j))
                ans = max(ans, i * j);
        }
    }
    cout << ans << endl;
    return 0;
}

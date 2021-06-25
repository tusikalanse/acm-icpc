/*
 * @Author: tusikalanse
 * @Date: 2021-06-25 21:57:35
 * @LastEditTime: 2021-06-25 22:04:22
 * @LastEditors: tusikalanse
 * @Description: factor
 * @FilePath: /ProjectEuler/12.cpp
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

vector<pair<int, int>> factor(LL n) {
    vector<pair<int, int>> ans;
    LL i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            int temp = 0;
            while (n % i == 0)
                n /= i, ++temp;
            ans.push_back(make_pair(i, temp));
        }
        ++i;
    }
    if (n != 1)
        ans.push_back(make_pair(n, 1));
    return ans;
}

int gao(vector<pair<int, int>> x) {
    long long ans = 1;
    for (auto &i : x) 
        ans *= i.second + 1;
    return ans;
}


int main() {
    long long temp = 1;
    for (int i = 2; ; ++i) {
        temp += i;
        int cnt = gao(factor(temp));
        cout << cnt << " " << temp << endl;
        if (cnt > 500)
            break;
    }
    return 0;
}

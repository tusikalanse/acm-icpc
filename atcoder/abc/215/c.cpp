/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-21 19:52:19
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-21 20:06:03
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

string s;
int k;
vector<string> v;

int main() {
    cin >> s >> k;
    sort(s.begin(), s.end());
    do {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << v[k - 1] << endl;
    return 0;
}
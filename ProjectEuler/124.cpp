/*
 * @Author: tusikalanse
 * @Date: 2021-08-20 20:25:38
 * @LastEditTime: 2021-08-20 20:41:20
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
vector<int> primefactors[N];

void getprime() {
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            primefactors[i].push_back(i);
            for (int j = i + i; j < N; j += i) {
                notprime[j] = 1;
                primefactors[j].push_back(i);
            }
        }
    }
}

struct rad {
    int prod, n;
    bool operator<(const rad& rhs) const { return make_pair(prod, n) < make_pair(rhs.prod, rhs.n); }
} a[N];

int n = 1e5;

int main() {
    getprime();
    a[1].n = a[1].prod = 1;
    for (int i = 2; i <= n; ++i) {
        a[i].n = i;
        a[i].prod = 1;
        for (int j : primefactors[i])
            a[i].prod *= j;
    }
    sort(a + 1, a + n + 1);
    cout << a[10000].n << " " << a[10000].prod << endl;
    return 0;
}
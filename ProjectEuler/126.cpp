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

int f(int x, int y, int z, int n) {
    return 2 * (x * y + y * z + x * z) + 4 * (n - 1) * (x + y + z + n - 2);
}

const int N = 1e5 + 10;
int s[N];

int main() {
    for (int x = 1; f(x, x, x, 1) < N; ++x) {
        for (int y = x; f(x, y, x, 1) < N; ++y) {
            for (int z = y; f(x, y, z, 1) < N; ++z) {
                for (int n = 1; f(x, y, z, n) < N; ++n)
                    s[f(x, y, z, n)]++;
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        cout << i << " " << s[i] << endl;
        if (s[i] == 1000) 
            break;
        }
    return 0;
}
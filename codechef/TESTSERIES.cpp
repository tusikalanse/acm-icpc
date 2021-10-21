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


int T;
int c[3];

int main() {
    cin >> T;
    while (T--) {
        c[0] = c[1] = c[2] = 0;
        for (int i = 0; i < 5; ++i) {
            int x; 
            cin >> x;
            c[x]++;
        }
        if (c[1] > c[2]) {
            cout << "INDIA" << endl;
        }
        else if (c[1] == c[2]) {
            cout << "DRAW" << endl;
        }
        else {
            cout << "ENGLAND" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, n, x, y, z;

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> x >> y >> z;
        int ans1 = (n - 1) / (x + y) + 1;
        if (n > z * x) {
            int ans2 = (n - z * x - 1) / (10 * y + x) + 1 + z;
            ans1 = min(ans1, ans2);
        }
        cout << ans1 << endl;
    }

    return 0;
}
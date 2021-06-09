#include <bits/stdc++.h>
using namespace std;

int a[110];

int main() {
    int T, n, flag;
    cin >> T;
    while (T--) {
        cin >> n;
        flag = 1;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (i != 1 && a[i] == a[i - 1])
                flag = 0;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
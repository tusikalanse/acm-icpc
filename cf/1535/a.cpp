#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        if (min(a, b) > max(c, d) || min(c, d) > max(a, b))
            cout << "NO\n";
        else 
            cout << "YES\n";
    }


    return 0;
}
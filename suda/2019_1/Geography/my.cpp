#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, R, x1, x2, x, y;
    cin >> T;
    while (T--) {
        cout << setprecision(15);
        cin >> R >> x1 >> x2 >> x >> y;
        y = abs(y);
        if (2 * R < x2 - x1)
            cout << -1 << endl;
        else if (x2 - x1 <= R || (y * y + (x - x1) * (x - x1) <= R * R && y * y + (x - x2) * (x - x2) <= R * R))
            cout << 0 << endl;
        else {
            double h = sqrt(R * R - 0.25 * (x2 - x1) * (x2 - x1));
            if (x > x1 && y * (x2 - x1) <= 2 * h * (x - x1)) {
                if (x * 2 > x1 + x2)
                    cout << sqrt(y * y + (x - x1) * (x - x1)) - R << endl;
                else 
                    cout << sqrt(y * y + (x - x2) * (x - x2)) - R << endl;
            }
            else if (x < x2 && y * (x2 - x1) <= 2 * h * (x2 - x)) {
                if (x * 2 > x1 + x2)
                    cout << sqrt(y * y + (x - x1) * (x - x1)) - R << endl;
                else 
                    cout << sqrt(y * y + (x - x2) * (x - x2)) - R << endl;
            }
            else
                cout << sqrt((y - h) * (y - h) + (x - (x1 + x2) / 2.0) * (x - (x1 + x2) / 2.0)) << endl;
        }
    }
    return 0;
}
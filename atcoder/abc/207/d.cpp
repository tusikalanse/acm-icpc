/*
 * @Author: tusikalanse
 * @Date: 2021-06-26 19:49:04
 * @LastEditTime: 2021-06-26 22:16:28
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/abc/207/d.cpp
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

const int N = 110;

int n;

bool isint(double x) {
    int d = x > 0 ? round(x) + 0.5 : round(x) - 0.5;
    return abs(d - x) < 1e-6;
}


int ppp(double x) {
    return x > 0 ? round(x) + 0.5 : round(x) - 0.5;
}

struct p {
    double a[N], b[N];
    bool rotate(double p) {
        for (int i = 0; i < n; ++i) {
            double temp = (a[i])*sin(p)+(b[i])*cos(p);
            a[i] = a[i] * cos(p) - b[i] * sin(p);
            b[i] = temp;
            if (!isint(a[i]) || !isint(b[i]))
                return false;
        }
        return true;
    }
    void move(int x, int y) {
        for (int i = 0; i < n; ++i) {
            a[i] += x;
            b[i] += y;
        }
    }
    bool equal(const p &rhs) const {
        set<pair<int, int>> s, t;
        for (int i = 0; i < n; ++i) {
            s.insert(make_pair(ppp(a[i]), ppp(b[i])));
            t.insert(make_pair(ppp(rhs.a[i]), ppp(rhs.b[i])));
        }
        return s == t;
    }
}S, T, temp;


int main() {
    cin >> n;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> S.a[i] >> S.b[i];
        sx += S.a[i];
        sy += S.b[i];
        S.a[i] *= n;
        S.b[i] *= n;
    }
    for (int i = 0; i < n; ++i) {
        S.a[i] -= sx;
        S.b[i] -= sy;
    }
    sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> T.a[i] >> T.b[i];
        sx += T.a[i];
        sy += T.b[i];
        T.a[i] *= n;
        T.b[i] *= n;
    }
    for (int i = 0; i < n; ++i) {
        T.a[i] -= sx;
        T.b[i] -= sy;
    }
    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    if (T.a[0] == 0 && T.b[0] == 0) {
        swap(T.a[0], T.a[1]);
        swap(T.b[0], T.b[1]);
    }
    for (int i = 0; i < n; ++i) {
        double angle0 = atan2(S.b[i], S.a[i]);
        double angle1 = atan2(T.b[0], T.a[0]);
        double delta = angle1 - angle0;
        temp = S;
        if (!temp.rotate(delta)) continue;
        if (temp.equal(T)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

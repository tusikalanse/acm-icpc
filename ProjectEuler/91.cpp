/*
 * @Author: tusikalanse
 * @Date: 2021-07-22 20:22:49
 * @LastEditTime: 2021-07-22 20:54:31
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

const int N = 50;

bool gao(int x1, int y1, int x2, int y2) {
    if (x1 * y1 + x2 * y2 == 0) return true;
    if ((x1 - x2) * x1 + (y1 - y2) * y1 == 0) return true;
    if ((x1 - x2) * x2 + (y1 - y2) * y2 == 0) return true;
    return false;
}

map<int, int> cnt;

int convert(int x1, int y1, int x2, int y2) {
    return x1 << 24 ^ y1 << 16 ^ x2 << 8 ^ y2;
}

int main() {
    int ans = 0;
    for (int px = 0; px <= N; ++px) {
        for (int py = 0; py <= N; ++py) {
            if (px == 0 && py == 0) continue;
            for (int qx = 0; qx <= N; ++qx) {
                for (int qy = 0; qy <= N; ++qy) {
                    if (qx == 0 && qy == 0) continue;
                    if (px == qx && py == qy) continue;
                    if (px * qy == py * qx) continue;
                    if (cnt[convert(px, py, qx, qy)]) continue;
                    if (gao(px, py, qx, qy)) {
                        // cout << px << " " << py << " " << qx << " " << qy << endl;
                        ans++;
                    }
                    cnt[convert(qx, qy, px, py)] = 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
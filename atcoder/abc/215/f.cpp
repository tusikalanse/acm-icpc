/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-21 19:52:21
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-21 21:26:42
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

const int N = 2e5 + 10;

int n;
struct node {
    int x, y;
    bool operator<(const node &rhs) const {
        if (y != rhs.y) 
            return y < rhs.y;
        return x < rhs.x;
    }
}p[N];

int ans = 0;
node LEFT[N], RIGHT[N];
int headleft = 0, headright = 0;

bool check(int dis, int id) {
    int l = 0, r = headleft - 1, now = -1, d = p[id].y;
    while (l <= r) {
        int mid = l + r >> 1;
        if (LEFT[mid].y >= d + dis) {
            r = mid - 1;
            now = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (now != -1 && abs(p[id].x - LEFT[now].x) >= dis) {
        return true;
    }
    l = 0, r = headright - 1, now = -1, d = p[id].y;
    while (l <= r) {
        int mid = l + r >> 1;
        if (RIGHT[mid].y >= d + dis) {
            l = mid + 1;
            now = mid;
        }
        else {
            r = mid - 1;
        }
    }
    if (now != -1 && abs(RIGHT[now].x - p[id].x) >= dis) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + n + 1);
    for (int i = n; i; --i) {
        p[i].x -= p[1].x;
        p[i].y -= p[1].y;
    }
    for (int i = 2; i <= n; ++i) {
        ans = max(ans, min(abs(p[i].x), abs(p[i].y)));
    }
    int mxx = 0;
    for (int i = 2; i <= n; ++i) {
        if (p[i].y == 0) 
            mxx = p[i].x;
        else
            break;
    }
    if (mxx) {
        for (int i = 2; i <= n; ++i) {
            ans = max(ans, min(abs(p[i].x - mxx), abs(p[i].y)));
        }
    }
    p[n + 1].x = p[n + 1].y = 2e9;
    for (int i = 2; i <= n; ++i) {
        if (p[i].y == 0) continue;
        if (p[i].y == p[i - 1].y) continue;
        while (headleft != 0 && LEFT[headleft - 1].x >= p[i].x) 
            headleft--;
        LEFT[headleft++] = p[i];
    }
    for (int i = n; i >= 2; --i) {
        if (p[i].y == 0) continue;
        if (p[i].y == p[i + 1].y) continue;
        if (headright == 0 || RIGHT[headright - 1].x < p[i].x)
            RIGHT[headright++] = p[i];
    }
    // cout << ans << endl;
    for (int i = 2; i <= n; ++i) {
        if (p[i].y == 0) continue;
        int l = ans + 1, r = 1e9, now = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid, i)) {
                l = mid + 1;
                now = mid;
            }
            else {
                r = mid - 1;
            }
        }
        if (now) {
            ans = max(ans, now);
        }
        // cout << i << " " << " " << p[i].x << " " << p[i].y << " " << ans << endl;
    }
    // for (int i = 0; i < headleft; ++i)
    //     cout << LEFT[i].x << " " << LEFT[i].y << " | ";
    // cout << endl;
    // for (int i = 0; i < headright; ++i)
    //     cout << RIGHT[i].x << " " << RIGHT[i].y << " | ";
    // cout << endl;
    cout << ans << endl;
    return 0;
}
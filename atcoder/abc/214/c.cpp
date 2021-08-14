/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-14 19:48:48
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-14 20:11:12
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, s[N], t[N];
int ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
    }
    int mnt = 2e9, id = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
        if (t[i] < mnt) {
            mnt = t[i];
            id = i;
        }
    }
    ans[id] = t[id];
    for (int i = 1; i < n; ++i) {
        ans[(id + i) % n] = min(ans[(id + i - 1) % n] + s[(id + i - 1) % n], t[(id + i) % n]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
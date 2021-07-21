/*
 * @Author: 12231227
 * @Date: 2021-07-20 13:03:16
 * @LastEditTime: 2021-07-20 13:09:03
 * @LastEditors: tusikalanse
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 5e3;
int a[N + 11][N + 11];
int f[N + 11][N + 11];

int s[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) cin >> a[i][j];
        for (int j = 1; j <= m; j++) {
            f[n][j] = 1;
            for (int i = n - 1; i >= 1; i--)
                if (a[i][j] <= a[i + 1][j]) f[i][j] = f[i + 1][j] + 1;
                else f[i][j] = 1;
        }
        int res = 1;
        for (int i = 1; i <= n; i++) {
            stack<pair<int, int>> st;
            st.push({0, 0});
            for (int j = 1; j <= m; ++j) {
                while (st.top().first >= f[i][j]) st.pop();
                s[j][0] = st.top().second;
                st.push({f[i][j], j});
            }
            while (!st.empty()) st.pop();
            st.push({0, m + 1});
            for (int j = m; j; --j) {
                while (st.top().first >= f[i][j]) st.pop();
                s[j][1] = st.top().second;
                st.push({f[i][j], j});
            }
            for (int j = 1; j <= m; ++j) {
                res = max(res, f[i][j] * (s[j][1] - s[j][0] - 1));
            }
        }
        cout << res << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int T, n, m, k, Q;
const int N = 4e7 + 10;
int c[N];

int main() {
    cin >> T;
    while(T--) {
        cin >> n >> m >> Q;
        m++;
        for(k = 1; k <= n; ++k) {
            long long temp = n - k + 1;
            long long ans = (m - 1) % temp;
            long long now = 1;
            while(1) {
                if((temp - ans) % (m - 1) == 0) {
                    long long x = (temp - ans) / (m - 1) - 1;
                    x = min(x, k - now);
                    ans += x * m;
                    now += x;
                    temp += x;
                    if(now == k) break;
                    ans = (ans + m) % (temp + 1);
                    now++;
                    temp++;
                    if(now == k) break;
                }
                else {
                    long long x = (temp - ans) / (m - 1);
                    x = min(x, k - now);
                    ans += x * m;
                    now += x;
                    temp += x;
                    if(now == k) break;
                    ans = (ans + m) % (temp + 1);
                    now++;
                    temp++;
                    if(now == k) break;
                }
            }
            //cout << 1 + ans << endl;
            ans =  1 + (ans - (m - 1) + n) % n;
            c[ans] = k;
        }
        while(Q--) {
            cin >> k;
            cout << c[k] << endl;
        }
    }

    return 0;
}
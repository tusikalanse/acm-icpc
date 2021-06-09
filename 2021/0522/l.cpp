#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int T, n, m;
struct node {
    int x, id;
    bool operator<(const node &rhs) const {
        return x < rhs.x;
    }
}a[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].x);
            a[i].id = 0;
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &a[i + n].x);
            a[i + n].id = 1;
        }
        sort(a + 1, a + n + m + 1);
        int ans = 0, temp = 0;
        for (int i = 1; i <= n + m;) {
            int j = i;
            int cnt0 = 0, cnt1 = 0;
            while (j <= n + m && a[j].x == a[i].x) {
                //cout << j << " == " << a[j].x << " " << a[j].id << endl;
                if (a[j].id == 0)
                    cnt0++;
                else
                    cnt1++;
                j++;
            }
            i = j;
            if (cnt1 == 0) {
                temp += cnt0;
                //cout << j - 1 << " " << temp << endl;
            }
            else {
                //           cout << j - 1 << " " << temp << " " << cnt0 <<  endl;
                ans = max(ans, temp);
                temp = 0;
            }
        }
        ans = max(ans, temp);
        if (ans == 0) {
            puts("Impossible");
        }
        else 
            printf("%d\n", ans);
    }

    return 0;
}
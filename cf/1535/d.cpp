#include <bits/stdc++.h>
using namespace std;

const int N = 262150;

char s[N], op[3];

int fa[N], son[N][2];
int ans[N];

int n, k, q, pos;

int main () {
    scanf("%d", &k);
    n = (1 << k) - 1;
    scanf("%s", s);
    int first = 0;
    for (int num = k - 1; ~num; --num) {
        int cnt = 1 << num;
        int now = cnt * 2 + 1;
        int now2 = cnt * 2;
        for (int i = first; i < first + cnt; ++i) {
            fa[i] = i / 2 * 2 + (now-- / 2);
            if (num == k - 1) 
                son[i][0] = son[i][1] = -1;
            else {
                son[i][0] = i - (now2--);
                son[i][1] = son[i][0] + 1;
            }
        }
        first += cnt;
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << fa[i] << " " << son[i][0] << " " << son[i][1] << endl;
    // }
    for (int i = 0; i < n; ++i) {
        if (son[i][0] == -1) {
            if (s[i] == '?')
                ans[i] = 2;
            else
                ans[i] = 1;
        }
        else {
            if (s[i] == '?')
                ans[i] = ans[son[i][0]] + ans[son[i][1]];
            else if (s[i] == '0')
                ans[i] = ans[son[i][0]];
            else if (s[i] == '1')
                ans[i] = ans[son[i][1]];
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d %s", &pos, op);
        pos--;
        s[pos] = op[0];
        int p = pos;
        while (p != n) {
            int i = p;
            if (son[i][0] == -1) {
                if (s[i] == '?')
                    ans[i] = 2;
                else
                    ans[i] = 1;
            }
            else {
                if (s[i] == '?')
                    ans[i] = ans[son[i][0]] + ans[son[i][1]];
                else if (s[i] == '0')
                    ans[i] = ans[son[i][0]];
                else if (s[i] == '1')
                    ans[i] = ans[son[i][1]];
            }
            p = fa[p];
        }
        printf("%d\n", ans[n - 1]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int ans[12], ok[12];
unordered_set<string> s;
char ss[15];
int T, n, cas, found, stat;
int ma[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool isfriday(int y, int m, int d) {
    return (1461 * (y + 4800 + (m - 14) / 12) / 4
           + 367 * (m - 2 - (m - 14) / 12 * 12) / 12
           - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4
           + d - 32075) % 7 == 4;
}

inline bool is29(int y) {
    return (!(y % 4) && (y % 100)) || !(y % 400);
}

inline bool isvalid(int y, int m, int d) {
    if(y < 1600) return false;
    if(m < 1 || m > 12) return false;
    if(d < 1) return false;
    return d <= ma[m] + (m == 2 && is29(y));
}

bool check() {
    for(auto si: s) {
        int y = 1000 * ans[(si[0] - 'A')] + 100 * ans[(si[1] - 'A')] + 10 * ans[(si[2] - 'A')] + ans[(si[3] - 'A')];
        int m = 10 * ans[(si[5] - 'A')] + ans[(si[6] - 'A')];
        int d = 10 * ans[(si[8] - 'A')] + ans[(si[9] - 'A')];
        if(!isvalid(y, m, d) || !isfriday(y, m, d)) return false;
    }
    return true;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); found = false; s.clear();
        for(int i = 0; i < 10; ++i) ans[i] = i, ok[i] = (1 << 10) - 1;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", ss);
            s.insert(ss);
            ok[ss[0] - 'A'] &= 0x3FE;
            ok[ss[5] - 'A'] &= 0x3;
            ok[ss[8] - 'A'] &= 0xF;
        }
        printf("Case #%d: ", ++cas);
        do {
            bool flag = true;
            for(int i = 0; i < 10; ++i) {
                if(!((ok[i] >> ans[i]) & 1)) {
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            if(check()) {
                found = 1;
                for(int i = 0; i < 10; ++i)
                    printf("%d", ans[i]);
                puts("");
                break;
            }
        } while(next_permutation(ans, ans + 10));
        if(!found)
            puts("Impossible");
    }
    return 0;
}
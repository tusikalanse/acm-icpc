#include <bits/stdc++.h>
using namespace std;

int n, cnt[26], T, cas;

char s[100008];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        n = strlen(s);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        int mx = 0;
        for (int i = 0; i < 26; ++i) {
            mx = max(mx, cnt[i]);
        }
        printf("Case #%d: %d\n", ++cas, mx);
    }

    return 0;
}
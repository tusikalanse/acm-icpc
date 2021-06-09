#include <bits/stdc++.h>
using namespace std;

char s[100010], t[1010];
int nxt[100010][26], fst[26];
int n, l, x;

int main() {
    scanf("%s%d", s, &n);
	l = strlen(s);
    memset(fst, -1, sizeof(fst));
    for(int i = 0; i < 26; ++i)
        nxt[l - 1][i] = -1;
    for(int i = l - 2; ~i; --i) {
        memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
        nxt[i][s[i + 1] - 'a'] = i + 1;
    }
    for(int i = 0; i < l; ++i) {
        if(fst[s[i] - 'a'] == -1)
            fst[s[i] - 'a'] = i;
    }
    while(n--) {
        scanf("%s", t);
        x = strlen(t);
        int p = fst[t[0] - 'a'];
        for(int i = 1; i < x; ++i) {
            if(p == -1) break;
            p = nxt[p][t[i] - 'a'];
        }
        if(p != -1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
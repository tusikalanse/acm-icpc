#include <bits/stdc++.h>
using namespace std;

char s[100005];
int main() {
    int cnt[26] = {0};
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        cnt[s[i] - 'a']++;
    }
    int c = 0, m = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i]) 
            c++;
        if(cnt[i] >= 2)
            m++;
    }
    if(c > 4 || c <= 1) 
        puts("NO");
    else if(c == 3 && m == 0)
        puts("NO");
    else if(c == 2 && m <= 1)
        puts("NO");
    else 
        puts("YES");

    return 0;
}

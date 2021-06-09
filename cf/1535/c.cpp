#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n;

char s[N];

vector<pair<int, int>> pos[3];

int gao(int x) {
    return x % 2 == s[x] - '0';
}

int main () {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        pos[0].clear();
        pos[1].clear();
        pos[2].clear();
        for (int i = 1, j; i <= n; i = j) {
            int first = i;
            j = i;
            while (j <= n && s[j] == '?') j++, first++;
            int f = gao(j);
            while (j <= n && (s[j] == '?' || gao(j) == f)) j++;
            while (i && (s[i] == '?' || gao(i) == f)) i--;
            pos[f].push_back(make_pair(i + 1, j - 1));
            if (i != 0)
                pos[2].push_back(make_pair(i + 1, first - 1));
        }
        long long ans = 0;
        for (int i = 0; i < pos[0].size(); ++i) {
            int len = pos[0][i].second - pos[0][i].first + 1;
            ans += 1LL * len * (len + 1) / 2;
            //cout << pos[0][i].first << " " << pos[0][i].second << endl;
        }
        //cout << "FESDFSD" << endl;
        for (int i = 0; i < pos[1].size(); ++i) {
            int len = pos[1][i].second - pos[1][i].first + 1;
            ans += 1LL * len * (len + 1) / 2;
           // cout << pos[1][i].first << " " << pos[1][i].second << endl;
        }
        //cout << "FESDFSD" << endl;
        for (int i = 0; i < pos[2].size(); ++i) {
            int len = pos[2][i].second - pos[2][i].first + 1;
            ans -= 1LL * len * (len + 1) / 2;
            //cout << pos[2][i].first << " " << pos[2][i].second << endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
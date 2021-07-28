/*
 * @Author: tusikalanse
 * @Date: 2021-07-28 16:18:09
 * @LastEditTime: 2021-07-28 17:02:20
 * @LastEditors: tusikalanse
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
//-------------------end head--------------

vector<string> words;

bool is_square(LL x) {
    int d = sqrtl(x + 0.5);
    return d * d == x;
}

int vis[10];
int rep[26];

LL ans = 0;

LL repr(const string& s) {
    LL res = 0;
    for (string::const_iterator it = s.begin(); it != s.end(); ++it) {
        res = res * 10 + rep[*it - 'A'];
    }
    return res;
}

void dfs(int now, const string& s, const string& t, int n) {
    if (now == n) {
        LL x = repr(s), y = repr(t);
        if (is_square(x) && is_square(y)) {
            ans = max(ans, max(x, y));
        }
        return;
    }
    if (~rep[s[now] - 'A']) {
        dfs(now + 1, s, t, n);
        return;
    }
    for (int i = s[now] == s[0] || s[now] == t[0]; i < 10; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        rep[s[now] - 'A'] = i;
        dfs(now + 1, s, t, n);
        rep[s[now] - 'A'] = -1;
        vis[i] = 0;
    }
}

int main() {
    string s;
    while (cin >> s) 
        words.push_back(s);
    int n = words.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (words[i].size() != words[j].size()) continue;
            vector<int> ci(26, 0), cj(26, 0);
            for (char ch: words[i])
                ci[ch - 'A']++;
            for (char ch: words[j])
                cj[ch - 'A']++;
            if (ci != cj) continue;
            memset(rep, -1, sizeof(rep));
            memset(vis, 0, sizeof(vis));
            dfs(0, words[i], words[j], words[i].size());
        }
    }
    cout << ans << endl;
    return 0;
}
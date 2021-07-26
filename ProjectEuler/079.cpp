/*
 * @Author: tusikalanse
 * @Date: 2021-07-19 08:03:47
 * @LastEditTime: 2021-07-19 08:13:46
 * @LastEditors: tusikalanse
 * @Description: topo sort
 * @FilePath: /ProjectEuler/79.cpp
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

vector<string> s = {
"319",
"680",
"180",
"690",
"129",
"620",
"762",
"689",
"762",
"318",
"368",
"710",
"720",
"710",
"629",
"168",
"160",
"689",
"716",
"731",
"736",
"729",
"316",
"729",
"729",
"710",
"769",
"290",
"719",
"680",
"318",
"389",
"162",
"289",
"162",
"718",
"729",
"319",
"790",
"680",
"890",
"362",
"319",
"760",
"316",
"729",
"380",
"319",
"728",
"716",
};

int g[10][10];
int in[10];
int vis[10];

string topo() {
    queue<int> q;
    string ans = "";
    for (int i = 0; i < 10; ++i) {
        if (vis[i] && in[i] == 0) {
            q.push(i);
            ans += to_string(i);
        }
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < 10; ++i) {
            if (g[t][i] && (in[i] -= g[t][i]) == 0) {
                q.push(i);
                ans += to_string(i);
            }
        }
    }
    return ans;
}

int main() {
    for (int i = 0; i < s.size(); ++i) {
        g[s[i][0] - '0'][s[i][1] - '0']++;
        g[s[i][1] - '0'][s[i][2] - '0']++;
        in[s[i][1] - '0']++;
        in[s[i][2] - '0']++;
        vis[s[i][0] - '0'] = 1;
        vis[s[i][1] - '0'] = 1;
        vis[s[i][2] - '0'] = 1;
    }
    cout << topo() << endl;
    return 0;
}

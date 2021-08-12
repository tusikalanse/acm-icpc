/*
 * @Author: tusikalanse
 * @Date: 2021-07-30 14:09:28
 * @LastEditTime: 2021-07-30 14:51:41
 * @LastEditors: tusikalanse
 * @Description: 108 + dfs, find first f[x] > 2 * 4'000'000 - 1
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

const int N = 2e5 + 10;

int prime[N];
bool notprime[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
    for (int i = 2; i < N; ++i) {
        if (!notprime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

struct state {
    LL cnt, num;
    vector<int> lis;
    bool operator<(const state& rhs) const {
        if (cnt == rhs.cnt)
            return num < rhs.num;
        return cnt > rhs.cnt;
    }
    bool operator>(const state& rhs) const { return rhs < *this; }
};

int limit = 4e6 * 2 - 1;
LL ans = 1e18;
unordered_map<LL, int> vis;

int main() {
    getprime();
    priority_queue<state, vector<state>, greater<state>> pq;
    state first;
    first.lis.push_back(1);
    first.cnt = 3;
    first.num = prime[1];
    pq.push(first);
    vis[prime[1]] = 1;
    while (!pq.empty()) {
        state u = pq.top();
        pq.pop();
        if (u.num > ans) {
            continue;
        }
        if (u.cnt > limit) {
            ans = min(ans, u.num);
            continue;
        }
        for (int i = 0; i < u.lis.size(); ++i) {
            if (i != 0 && u.lis[i] == u.lis[i - 1])
                continue;
            state temp = u;
            temp.cnt /= (2 * temp.lis[i] + 1);
            temp.lis[i]++;
            temp.num *= prime[i + 1];
            temp.cnt *= (2 * temp.lis[i] + 1);
            if (!vis[temp.num]) {
                pq.push(temp);
                vis[temp.num] = 1;
            }
        }
        state temp = u;
        temp.lis.push_back(1);
        temp.cnt *= 3;
        temp.num *= prime[temp.lis.size()];
        if (!vis[temp.num]) {
            pq.push(temp);
            vis[temp.num] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
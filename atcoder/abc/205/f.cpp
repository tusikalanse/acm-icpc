/*
 * @Author: tusikalanse
 * @Date: 2021-06-13 22:01:17
 * @LastEditTime: 2021-06-15 09:34:23
 * @LastEditors: tusikalanse
 * @Description: Maxflow
 * @FilePath: /atcoder/abc/205/f.cpp
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

const int N = 22000;

struct e {
    int to, w, next;
}edge[N << 1];
int head[500], dep[500], cur[500], cnt = 0;
int s, t;

void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}

void add_edge(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool bfs() {
    memset(dep, -1, sizeof(dep));
    memcpy(cur, head, sizeof(cur));
    dep[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next) {
            if (edge[i].w > 0 && dep[edge[i].to] == -1) {
                dep[edge[i].to] = dep[u] + 1;
                q.push(edge[i].to);
            }
        }
    }
    return dep[t] != -1;
}

int dfs(int s, int flow) {
    if (s == t) 
        return flow;
    int remain = flow;
    for (int i = cur[s]; ~i && remain; i = edge[i].next) {
        cur[s] = i;
        int vol = edge[i].w, to = edge[i].to;
        if (vol > 0 && dep[to] == dep[s] + 1) {
            int c = dfs(to, min(vol, remain));
            remain -= c;
            edge[i].w -= c;
            edge[i ^ 1].w += c;
        }
    }
    return flow - remain;
}

int dinic() {
    int ans = 0;
    while (bfs()) 
        ans += dfs(s, INF);
    return ans;
}

int h, w, n;

int main() {
    init();
    cin >> h >> w >> n;
    int total = 2 + h + w + 2 * n;
    s = 0, t = total - 1;
    //s -> h -> n1 -> n2 -> w -> t
    //s : 0
    //h : 1 ~ h
    //n1: h + 1 ~ h + n
    //n2: h + n + 1 ~ h + 2n
    //w : h + 2n + 1 ~ h + 2n + w
    //t : h + 2n + w + 1
    for (int i = 1; i <= h; ++i) {
        add_edge(s, i, 1);
        add_edge(i, s, 0);
    }
    for (int i = 1; i <= w; ++i) {
        add_edge(h + 2 * n + i, t, 1);
        add_edge(t, h + 2 * n + i, 0);
    }
    for (int i = 1; i <= n; ++i) {
        add_edge(h + i, h + n + i, 1);
        add_edge(h + n + i, h + i, 0);
    }
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j <= c; ++j) {
            add_edge(j, h + i, 1);
            add_edge(h + i, j, 0);
        }
        for (int j = b; j <= d; ++j) {
            add_edge(h + n + i, h + 2 * n + j, 1);
            add_edge(h + 2 * n + j, h + n + i, 0);
        }
    }
    cout << dinic() << endl;
    return 0;
}



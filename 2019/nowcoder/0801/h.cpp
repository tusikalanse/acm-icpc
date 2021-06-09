#include <bits/stdc++.h>
using namespace std;
#define OUT puts("-1"), exit(0)
const int N = 1e4 + 10;
using LL = long long;
vector<int> G[N << 3];
int id[N << 3];
int deg[N << 3], in[N << 2], out[N << 2], pos[N], n, m, tot;
int mp[N];
int l[20], r[20], cnt[20];
int len[50];
char cons[50][10010], cc[50][3];

inline void add(int x, int y) {
   // cout << x << " ----> " << y << endl;
    G[x].push_back(y);
    deg[y]++;
}

void build_in(int rt, int l, int r) {
    if(l == r) {
        pos[l] = rt;
        id[rt] = l;
        return;
    }
    int mid = l + r >> 1;
    build_in(rt << 1, l, mid);
    build_in(rt << 1 | 1, mid + 1, r);
    add(rt, rt << 1); //in树父亲向儿子建边
    add(rt, rt << 1 | 1);
}

void build_out(int rt, int l, int r) {
    add(rt, tot + rt); //in树向out树建边
    if(l == r) {
        return;
    }
    int mid = l + r >> 1;
    build_out(rt << 1, l, mid);
    build_out(rt << 1 | 1, mid + 1, r);
    add(tot + (rt << 1), tot + rt); //out树儿子向父亲建边
    add(tot + (rt << 1 | 1), tot + rt);
}

void update_in(int rt, int l, int r, int L, int R, int from) {
    if(L <= l && r <= R) {
        add(tot + pos[from], rt);
        return;
    }
    int mid = l + r >> 1;
    if(L <= mid)
        update_in(rt << 1, l, mid, L, R, from);
    if(mid < R)
        update_in(rt << 1 | 1, mid + 1, r, L, R, from);
}

void update_out(int rt, int l, int r, int L, int R, int pnt) {
    if(L <= l && r <= R) {
        add(tot + rt, pos[pnt]);
        return;
    }
    int mid = l + r >> 1;
    if(L <= mid)
        update_out(rt << 1, l, mid, L, R, pnt);
    if(mid < R)
        update_out(rt << 1 | 1, mid + 1, r, L, R, pnt);
}

bool topo() {
    queue<pair<int, int>> que;
    vector<int> ans;
    que.push({-1, 1});
    while(!que.empty()) {
        pair<int, int> u = que.front();
        que.pop();
        if(u.first != -1)
            ans.push_back(u.first);
        for(auto &it: G[u.second])
            if(--deg[it] == 0)
                que.push(make_pair(~id[it] ? mp[id[it]] : -1, it));
    }
    if(ans.size() != n) return false;
    for(int i = 0; i < ans.size(); ++i)
        printf("%c", 'a' + ans[i] - 1);
    puts("");
    return true;
}


int main() {
    memset(id, -1, sizeof(id));
    scanf("%d%d", &n, &m);
    memset(cnt, -1, sizeof(cnt));
    for(int i = 1; i <= m * (m - 1) / 2; ++i) {
        scanf("%s%d", cc[i], &len[i]);
        if(len[i]) scanf("%s", cons[i]);
        tot += len[i];
        int c0 = 0, c1 = 0;
        for(int j = 0; j < len[i]; ++j) {
            if(cons[i][j] == cc[i][0]) c0++;
            else c1++;
        }
        if(cnt[cc[i][0] - 'a' + 1] != -1 && cnt[cc[i][0] - 'a' + 1] != c0) OUT;
        cnt[cc[i][0] - 'a' + 1] = c0;
        if(cnt[cc[i][1] - 'a' + 1] != -1 && cnt[cc[i][1] - 'a' + 1] != c1) OUT;
        cnt[cc[i][1] - 'a' + 1] = c1;
    }
    if(tot != n * (m - 1)) OUT;
    for(int i = 1; i <= m; ++i) {
        l[i] = r[i - 1] + 1;
        r[i] = l[i] + cnt[i] - 1;
        for(int j = l[i]; j <= r[i]; ++j)
            mp[j] = i;
    }
    tot = n << 2;
    build_in(1, 1, n); build_out(1, 1, n);
    for(int i = 1; i <= m * (m - 1) / 2; ++i) {
        int c0 = 0, c1 = 0;
        for(int j = 0; j < len[i]; ++j) {
            if(cons[i][j] == cc[i][0]) {
                if(c0 != 0)
                    update_out(1, 1, n, l[cc[i][0] - 'a' + 1], l[cc[i][0] - 'a' + 1] + c0 - 1, l[cc[i][0] - 'a' + 1] + c0);
                if(c0 != cnt[cc[i][0] - 'a' + 1] - 1)
                    update_in(1, 1, n, l[cc[i][0] - 'a' + 1] + c0 + 1, r[cc[i][0] - 'a' + 1], l[cc[i][0] - 'a' + 1] + c0);
                if(c1 != 0) 
                    update_out(1, 1, n, l[cc[i][1] - 'a' + 1], l[cc[i][1] - 'a' + 1] + c1 - 1, l[cc[i][0] - 'a' + 1] + c0);
                if(c1 != cnt[cc[i][1] - 'a' + 1])
                    update_in(1, 1, n, l[cc[i][1] - 'a' + 1] + c1, r[cc[i][1] - 'a' + 1], l[cc[i][0] - 'a' + 1] + c0);
                c0++;
            }  
            else {
                if(c1 != 0)
                    update_out(1, 1, n, l[cc[i][1] - 'a' + 1], l[cc[i][1] - 'a' + 1] + c1 - 1, l[cc[i][1] - 'a' + 1] + c1);
                if(c1 != cnt[cc[i][1] - 'a' + 1] - 1)
                    update_in(1, 1, n, l[cc[i][1] - 'a' + 1] + c1 + 1, r[cc[i][1] - 'a' + 1], l[cc[i][1] - 'a' + 1] + c1);
                c1++;
            }
        }
    }
    if(!topo()) OUT;
    return 0;
}
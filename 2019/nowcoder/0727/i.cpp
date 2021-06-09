#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct PAM {
    int fail, cnt, len;
    int nxt[26];
}st[N];

long long ans, cnt_minus;
char s[N], rs[N];
int n, now, sz, cnt_rev;
void pam_init() {
    memset(st, 0, sizeof(st));
    st[0].fail = st[1].fail = 1;
    st[1].len = -1;
    sz = 1;
}

void extend(int c,int pos) {
    int p = now;
    while (s[pos - st[p].len - 1] != s[pos]) p = st[p].fail;
    if (!st[p].nxt[c]) {
        int np = ++sz, q = st[p].fail;
        st[np].len = st[p].len + 2;
        while(s[pos - st[q].len - 1] != s[pos]) q = st[q].fail;
        st[np].fail = st[q].nxt[c];
        st[p].nxt[c] = np;
    }
    now = st[p].nxt[c];
    st[now].cnt++;
}

namespace SAM {
    int len[N << 1], nxt[N << 1][26], par[N << 1], match[N << 1], c[N], pos[N << 1];
    int sz, last;
    int new_node(int l) {
        len[sz] = l;
        memset(nxt[sz], 0, sizeof(nxt[sz]));
        return sz++;
    }

    void init() {
        sz = last = 0;
        par[sz] = -1;
        new_node(0);
    }

    void add(int c) {
        int p = last, np = new_node(len[last] + 1);
        for(; ~p && !nxt[p][c]; p = par[p]) nxt[p][c] = np;
        if(-1 == p) par[np] = 0;
        else {
            int q = nxt[p][c];
            if(len[q] == len[p] + 1) par[np] = q;
            else {
                int nq = new_node(len[p] + 1);
                memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
                par[nq] = par[q];
                par[q] = par[np] = nq;
                for(; ~p && nxt[p][c] == q; p = par[p])
                    nxt[p][c] = nq;
            }
        }
        last = np;
    }

    void topo() {
        for(int i = 0; i <= n; ++i) c[i] = 0;
        for(int i = 0; i < sz; ++i) c[len[i]]++;
        for(int i = 1; i <= n; ++i) c[i] += c[i - 1];
        for(int i = sz - 1; ~i; --i) pos[--c[len[i]]] = i;
    }

    long long calc() {
        long long res = 0;
        for(int i = sz - 1; ~i; --i) {
            int j = pos[i];
            if(j == 0) continue;
            if(~par[j])
                match[par[j]] = max(match[par[j]], match[j]);
            res += max(0, min(len[j], match[j]) - len[par[j]]);
        }
        return res;
    }
}

int main() {
    scanf("%s",s);
    pam_init();
    n = strlen(s);
    for(int i = 0; i < n; ++i)
        extend(s[i] - 'a', i);
    cnt_rev = sz - 1;
    SAM::init();
    for(int i = 0; i < n; ++i)
        SAM::add(s[i] - 'a');
    for(int i = 1; i < SAM::sz; ++i) {
        ans += SAM::len[i] - SAM::len[SAM::par[i]];
    }
    for(int i = 0; i < n; ++i) {
        rs[i] = s[n - i - 1];
    }
    rs[n] = '\0';
    int p = 0, l = 0;
    for(int i = 0; i < n; ++i) {
        int x = rs[i] - 'a';
        while(~p && !SAM::nxt[p][x])
            p = SAM::par[p], l = SAM::len[p];
        if(p == -1) {
            p = l = 0;
            continue;
        }
        p = SAM::nxt[p][x], l++;
        SAM::match[p] = max(SAM::match[p], l);
    }
    SAM::topo();
    cnt_minus = SAM::calc();
    cnt_minus = (cnt_minus - cnt_rev) / 2;
    printf("%lld\n", ans - cnt_minus);
    return 0;
}
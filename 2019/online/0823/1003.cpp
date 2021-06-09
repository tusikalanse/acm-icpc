#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n, m, i, j, k, cnt;
int q, l, r, T;
int LOG2[MAXN];
namespace SA {
    int wa[MAXN], wb[MAXN], c[MAXN], r[MAXN], sa[MAXN], *rnk, height[MAXN], RMQ[MAXN][20];
    char s[MAXN];
    void build_sa(int r[], int sa[], int n, int m) {
        int i, j, k, p = 0, *x = wa, *y = wb;
        for(i = 0; i < m; ++i) c[i] = 0;
        for(i = 0; i < n; ++i) c[x[i] = r[i]]++;
        for(i = 1; i < m; ++i) c[i] += c[i - 1];
        for(i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
        for(k = 1; p < n; k <<= 1, m = p) {
            p = 0;
            for(i = n - k; i < n; ++i) y[p++] = i;
            for(i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
            for(i = 0; i < m; ++i) c[i] = 0;
            for(i = 0; i < n; ++i) c[x[y[i]]]++;
            for(i = 1; i < m; ++i) c[i] += c[i - 1];
            for(i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for(i = 1; i < n; ++i)
                x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++;
        }
        rnk = x;
    }

    void get_height(int r[], int sa[], int n) {
        int i, j, k = 0;
        for(i = 0; i < n; height[rnk[i++]] = k)
            for(k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
    }

    void RMQ_init(int n) {
        for(int i = 0; i <= n; ++i)
            RMQ[i][0] = height[i];
        for(int j = 1; (1 << j) <= n + 1; ++j) {
            for(int i = 0; i + (1 << j) <= n + 1; ++i) 
                RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
        }
    }

    int query(int l, int r) {
        if(l == r) return n - rnk[l];
        l = rnk[l]; r = rnk[r];
        if(l > r)
            swap(l, r);
        l++;
        int k = LOG2[r - l + 1];
        return min(RMQ[l][k], RMQ[r - (1 << k) + 1][k]);
    }
}

struct node {
    int l, r, sum;
}Tree[MAXN * 30];
int root[MAXN];

void init() {
    cnt = 0;
    root[0] = 0;
    Tree[0].l = Tree[0].r = Tree[0].sum = 0;
}

void update(int &rt, int l, int r, int num) {
    Tree[++cnt] = Tree[rt];
    rt = cnt;
    Tree[rt].sum++;
    if(l == r)
        return;
    int mid = l + r >> 1;
    if(num <= mid)
        update(Tree[rt].l, l, mid, num);
    else
        update(Tree[rt].r, mid + 1, r, num);
}

int query(int i, int j, int k, int l, int r) {
    if(l == r)
        return l;
    int mid = l + r >> 1;
    int d = Tree[Tree[j].l].sum - Tree[Tree[i].l].sum;
    if(k <= d)
        return query(Tree[i].l, Tree[j].l, k, l, mid);
    else
        return query(Tree[i].r, Tree[j].r, k - d, mid + 1, r);
}

int main() {
    LOG2[1] = 0;
    for(int i = 1; (1 << i) < MAXN; ++i) {
        for(int j = 1 << i; j < (2 << i) && j < MAXN; ++j)
            LOG2[j] = i;
    }
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%s", &n, &q, SA::s);
        for(int i = 0; i < n; ++i)
            SA::r[i] = SA::s[i];
        SA::build_sa(SA::r, SA::sa, n + 1, 200);
        SA::get_height(SA::r, SA::sa, n);
        SA::RMQ_init(n);
        init();
        for(int i = 1; i <= n; ++i) {
            root[i] = root[i - 1];
            update(root[i], 1, n, SA::sa[i] + 1);
        }
        while(q--) {
            scanf("%d%d%d", &l, &r, &k);
            int pos = SA::rnk[l - 1], up = pos, down = pos, L, R, len = r - l + 1;
            L = 1, R = pos - 1;
            while(L <= R) {
                int mid = L + R >> 1;
                if(SA::query(SA::sa[mid], SA::sa[pos]) >= len) {
                    down = mid;
                    R = mid - 1;
                }
                else 
                    L = mid + 1;
            }
            L = pos + 1, R = n;
            while(L <= R) {
                int mid = L + R >> 1;
                if(SA::query(SA::sa[mid], SA::sa[pos]) >= len) {
                    up = mid;
                    L = mid + 1;
                }
                else
                    R = mid - 1;
            }
            if(up - down + 1 < k) {
                puts("-1");
            } 
            else 
                printf("%d\n", query(root[down - 1], root[up], k, 1, n));
        }
    }
    return 0;
}
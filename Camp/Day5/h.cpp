#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
const int MAXN = 300010, mod = 1e9 + 7;
vector <int> E[maxn];
// ------ whnb -------//
int size[MAXN], top[MAXN], fa[MAXN], son[MAXN], dep[MAXN], dfn[MAXN], rnk[MAXN], cnt, root;
int head[MAXN], pnt[MAXN << 1], nxt[MAXN << 1], num;
long long sum[MAXN << 2], lazy[MAXN << 2];
int T, n, a, b, c, m;
// ------ whnb -------//
long long COUNT[maxn];
long long SIG;
long long Sigma;
int pre[maxn];
void addedge(int u,int v){
    E[u].push_back(v);
    E[v].push_back(u);
}

long long dfs0(int u,int fuck){
    pre[u] = fuck;
    for (int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if (v==fuck) continue;
        COUNT[u]=(COUNT[u]+dfs0(v,u))%mod;
    }
    COUNT[u]=(COUNT[u]+n)%mod;
    Sigma=(Sigma+COUNT[u]*(SIG-COUNT[u])%mod)%mod;
    return COUNT[u];
}

long long sumT;
long long dfs(int u,int pre){
    long long res=0;
    for (int i=head[u];i!=-1;i=nxt[i]){
        int v=pnt[i];
        if (v==pre)continue;
        res=(res+dfs(v,u))%mod; 
    }
    res=(res+1)%mod;
    if (u!=1) sumT=(sumT+1LL*res*(SIG-res))%mod;
    return res;
}

// ------------- whnb ---------------//

void add(int x, int y) {
    pnt[num] = y;
    nxt[num] = head[x];
    head[x] = num++;
}

void dfs1(int u, int pre, int depth) {
    size[u] = 1;
    fa[u] = pre;
    son[u] = -1;
    dep[u] = depth;
    for(int i = head[u]; ~i; i = nxt[i]) if(pnt[i] != pre) {
        int v = pnt[i];
        dfs1(v, u, depth + 1);
        size[u] += size[v];
        if(son[u] == -1 || size[v] > size[son[u]]) 
            son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = cnt;
    rnk[cnt] = u;
    cnt++;
    if(son[u] == -1)
        return;
    dfs2(son[u], t);
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(v != fa[u] && v != son[u])
            dfs2(v, v);
    }
}

void pushup(int rt) {
    sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % mod;
}

void pushdown(int rt, int l, int r) {
    if(lazy[rt]) {
        int mid = l + r >> 1;
        lazy[rt << 1] = (lazy[rt] + lazy[rt << 1]) % mod;
        lazy[rt << 1 | 1] = (lazy[rt] + lazy[rt << 1 | 1]) % mod;
        sum[rt << 1] = (sum[rt << 1] + 1LL * lazy[rt] * (mid - l + 1) % mod) % mod;
        sum[rt << 1 | 1] = (sum[rt << 1 | 1] + 1LL * lazy[rt] * (r - mid) % mod) % mod;
        lazy[rt] = 0;
    }
}

void build(int rt, int l, int r) {
    lazy[rt] = 0;
    if(l == r) {
        sum[rt] = size[rnk[l]];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

long long query(int rt, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    pushdown(rt, l, r);
    long long ans = 0;
    int mid = l + r >> 1;
    if(mid >= L)
        ans = (ans + query(rt << 1, l, mid, L, R)) % mod;
    if(mid < R)
        ans = (ans + query(rt << 1 | 1, mid + 1, r, L, R)) % mod;
    return ans;
}

void update(int rt, int l, int r, int L, int R, int val) {
    if(L <= l && r <= R) {
        lazy[rt] += val;
        lazy[rt] %= mod;
        sum[rt] += 1LL * val * (r - l + 1) % mod;
        sum[rt] %= mod;
        return;
    }
    pushdown(rt, l, r);
    int mid = l + r >> 1;
    if(mid >= L)
        update(rt << 1, l, mid, L, R, val);
    if(mid < R)
        update(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);
}

void init() {   
    num = cnt = 1;
    root = 1;
    memset(head, -1, sizeof(head));
    int a, b;
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    dfs1(root, 0, 1);
    dfs2(root, root);
    build(1, 1, n);
}

int query(int va, int vb, int& lenth) {
    lenth = 0;
    int f1 = top[va], f2 = top[vb];
    long long ans = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) 
            swap(va, vb), swap(f1, f2);
        ans = (ans + query(1, 1, n, dfn[f1], dfn[va])) % mod;
        lenth += dfn[va] - dfn[f1] + 1;
        va = fa[f1];
        f1 = top[va];
    }
    if(dep[va] > dep[vb]) swap(va, vb);
    lenth += dfn[vb] - dfn[va] + 1;
    ans = (ans + query(1, 1, n, dfn[va], dfn[vb])) % mod;
    lenth--;
    return ans;
}

void change(int va, int vb, long long val) {
    val %= mod;
    int f1 = top[va], f2 = top[vb];
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) 
            swap(va, vb), swap(f1, f2);
        update(1, 1, n, dfn[f1], dfn[va], val);
        va = fa[f1];
        f1 = top[va];
    }
    if(dep[va] > dep[vb]) swap(va, vb);
    update(1, 1, n, dfn[va], dfn[vb], val);
}


// --------------- whnb --------------------//
struct ele{
    int u; //index of node
    int to; //ascending tree;
};

vector<ele> qseq[maxn];
int main(void){
        long long ans=0;
        scanf("%d%d", &n, &m);
        init();
        for (int i=1;i<m;i++){
            int a,b,u,v;
            scanf("%d%d%d%d",&a,&b,&u,&v);
            addedge(a,b);
            qseq[a].push_back({u,b});
            qseq[b].push_back({v,a});
        }
        SIG=(1LL*n*m)%mod;
        dfs0(1,0); dfs(1,0);
        ans=(ans+Sigma)%mod;
        ans=(ans+sumT*m%mod)%mod;
        for (int i=1;i<=m;i++){
            ele tmp;
            for (int j=0;j<qseq[i].size();j++){
                long long x;
                tmp=qseq[i][j];
                int u=tmp.u;
                int aT=tmp.to;
                if (u==1) continue;
                if (pre[aT]==i){
                    x=COUNT[aT]%mod;
                }else{
                    x=((SIG-COUNT[i])%mod+mod)%mod;
                }
                int lenth, ignore;
                long long sig=query(1,u,lenth)-query(1,1,ignore);
                sig %= mod;
                ans=((ans-((x*x%mod)*lenth)%mod+SIG*x%mod*lenth%mod - 2LL*x%mod*sig%mod)%mod+mod)%mod;
                change(1,u,x);
            }
            for (int j=qseq[i].size()-1;j>=0;j--){
                long long x;
                tmp=qseq[i][j];
                int u=tmp.u;
                int aT=tmp.to;
                if (u==1) continue;
                if (pre[aT]==i){
                    x=COUNT[aT]%mod;
                }else{
                    x=((SIG-COUNT[i])%mod+mod)%mod;
                }
                change(1,u,(mod - x) % mod);
            }
        }
        ans %= mod;
        ans = (ans + mod) % mod;
        printf("%lld\n", ans);
        return 0;
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace fastIO {    
    #define BUF_SIZE 100000    
    #define OUT_SIZE 100000    
    #define ll long long    
    //fread->read    
    bool IOerror=0;    
    inline char nc() {    
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;    
        if (p1 == pend) {    
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);    
            if (pend == p1) {
                IOerror = 1;
                exit(0);
                return -1;
            }    
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}    
        }    
        return *p1++;    
    }    
    inline bool blank(char ch){return ch == ' '|| ch == '\n'|| ch == '\r'|| ch == '\t';}    
    inline void read(int &x){    
        bool sign=0; char ch=nc(); x=0;    
        for (;blank(ch);ch=nc());    
        if (IOerror)return;    
        if (ch=='-')sign=1,ch=nc();    
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';    
        if (sign)x=-x;    
    }    
    inline void read(ll &x){    
        bool sign=0; char ch=nc(); x=0;    
        for (;blank(ch);ch=nc());    
        if (IOerror)return;    
        if (ch=='-')sign=1,ch=nc();    
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';    
        if (sign)x=-x;    
    }      
    inline void read(double &x){    
        bool sign=0; char ch=nc(); x=0;    
        for (;blank(ch);ch=nc());    
        if (IOerror)return;    
        if (ch=='-')sign=1,ch=nc();    
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';    
        if (ch=='.'){    
            double tmp=1; ch=nc();    
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');    
        }    
        if (sign)x=-x;    
    }    
    inline void read(char *s){    
        char ch=nc();    
        for (;blank(ch);ch=nc());    
        if (IOerror)return;    
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;    
        *s=0;    
    }    
    inline void read(char &c){    
        for (c=nc();blank(c);c=nc());    
        if (IOerror){c=-1;return;}    
    }   
    #undef OUT_SIZE    
    #undef BUF_SIZE    
}; using namespace fastIO;  

const int N = 1e5 + 10;

struct node {
    int val, id;
    bool operator<(const node &rhs) {
        return val > rhs.val;
    }
}t[N];

int n, q, cnt, root[N], rnk[N];
LL sum[N];
int b[N][32], a[N], s[100];

void pre() {
    for(int i = 1; i <= n; ++i) {
        int cc = 0;
        while(a[i]) {
            s[++cc] = (a[i] - a[i] / 2);
            a[i] /= 2;
        }
        for(int j = 31;; --j) {
            if(cc) {
                b[i][j] = s[cc--];
            }
            else
                break;
        }
    }
}

struct {
    int l, r, k;
    LL ans;
}que[N * 5];

struct {
    int l, r, num;
    LL sum;
}pst[N * 40];

void init() {
    cnt = 0;
    root[0] = pst[0].l = pst[0].r = 0;
    pst[0].sum = pst[0].num = 0;
}

void update(int &rt, int l, int r, int pos) {
    pst[++cnt] = pst[rt];
    rt = cnt;
    pst[rt].num++;
    pst[rt].sum += t[pos].val;
    if(l == r) {
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid)
        update(pst[rt].l, l, mid, pos);
    else
        update(pst[rt].r, mid + 1, r, pos);
}

LL query(int i, int j, int k, int l, int r) {
    if(l == r) {
        if(k == 0)
            return 0;
        return pst[j].sum - pst[i].sum;
    }
    int d = pst[pst[j].l].num - pst[pst[i].l].num;
    int mid = l + r >> 1;
    if(d >= k)
        return query(pst[i].l, pst[j].l, k, l, mid);
    else
        return pst[pst[j].l].sum - pst[pst[i].l].sum + query(pst[i].r, pst[j].r, k - d, mid + 1, r);
}

void gao(int dim) {
    for(int i = 1; i <= n; ++i) {
        t[i].val = b[i][dim];
        t[i].id = i;
    }
    sort(t + 1, t + n + 1);
    for(int i = 1; i <= n; ++i) {
        rnk[t[i].id] = i;
    }
    init();
    for(int i = 1; i <= n; ++i) {
        root[i] = root[i - 1];
        if(t[rnk[i]].val != 0)
            update(root[i], 1, n, rnk[i]);
    }
    for(int i = 1; i <= q; ++i) {
        if(que[i].k == 0) continue;
        int d = pst[root[que[i].r]].num - pst[root[que[i].l - 1]].num;
        if(d >= que[i].k) {
            que[i].ans -= query(root[que[i].l - 1], root[que[i].r], que[i].k, 1, n);
            que[i].k = 0;
        }
        else {
            que[i].ans -= query(root[que[i].l - 1], root[que[i].r], d, 1, n);
            que[i].k -= d;
        }
    }
}

int main() {
	read(n);
	read(q);
    for(int i = 1; i <= n; ++i) {
        read(a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= q; ++i) {
    	read(que[i].l);
    	read(que[i].r);
    	read(que[i].k);
        que[i].ans = sum[que[i].r] - sum[que[i].l - 1];
    }
    pre();
    for(int i = 1; i <= 31; ++i) {
        gao(i);
    }
    for(int i = 1; i <= q; ++i) {
        printf("%lld\n", que[i].ans);
    }
    return 0;
}
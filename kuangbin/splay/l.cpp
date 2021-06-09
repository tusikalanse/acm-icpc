#include <bits/stdc++.h>
#define LL long long;
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;
int a[N], n, m, A, B, C;
char ch[20];

namespace fastIO{    
    #define BUF_SIZE 100000    
    #define OUT_SIZE 100000    
    #define ll long long    
    //fread->read    
    bool IOerror=0;    
    inline char nc(){    
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;    
        if (p1==pend){    
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);    
        if (pend==p1){IOerror=1;exit(0);return -1;}    
        //{printf("IO error!\n");system("pause");for (;;);exit(0);}    
    }    
    return *p1++;    
}    
inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}    
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



struct SplayTree {
    bool first;
    int ch[N][2], fa[N], size[N], sz, root;
    int sum[N], lmax[N], rmax[N], mx[N];
    int rev[N], num[N], lazy[N];
    int stk[N], top;

    void clear(int rt) {
        ch[rt][0] = ch[rt][1] = fa[rt] = size[rt] = sum[rt] = lmax[rt] = rmax[rt] = mx[rt] = rev[rt] = lazy[rt] = 0;
    }

    void newnode(int pre, int val, int &rt) {
        if(top)
            rt = stk[--top];
        else
            rt = ++sz;
        fa[rt] = pre;
        num[rt] = lmax[rt] = rmax[rt] = sum[rt] = mx[rt] = val;
        ch[rt][0] = ch[rt][1] = 0;
        size[rt] = 1;
        rev[rt] = lazy[rt] = 0;
    }

    void pushup(int rt) {
        size[rt] = 1 + size[ch[rt][0]] + size[ch[rt][1]];
        sum[rt] = num[rt] + sum[ch[rt][0]] + sum[ch[rt][1]];
        int ls0 = -INF, ls1 = -INF, rs0 = -INF, rs1 = -INF, s0 = 0, s1 = 0, mx0 = -INF, mx1 = -INF;
        if(ch[rt][0]) {
            ls0 = lmax[ch[rt][0]];
            rs0 = rmax[ch[rt][0]];
            mx0 = mx[ch[rt][0]];
        }
        if(ch[rt][1]) {
            ls1 = lmax[ch[rt][1]];
            rs1 = rmax[ch[rt][1]];
            mx1 = mx[ch[rt][1]];
        }
        lmax[rt] = max(ls0, sum[ch[rt][0]] + num[rt] + max(ls1, 0));
        rmax[rt] = max(rs1, sum[ch[rt][1]] + num[rt] + max(rs0, 0));
        mx[rt] = max(max(mx0, mx1), max(rs0, 0) + num[rt] + max(ls1, 0));
    }

    void build(int pre, int l, int r, int &rt) {
        if(l > r) return;
        int mid = l + r >> 1;
        newnode(pre, a[mid], rt);
        build(rt, l, mid - 1, ch[rt][0]);
        build(rt, mid + 1, r, ch[rt][1]);
        if(l != r) pushup(rt);
    }

    void init() {
        root = sz = top = 0;
        clear(root);
        build(0, 0, n + 1, root);
        pushup(root);
    }

    void reverse(int rt) {
        if(!rt) return;
        swap(lmax[rt], rmax[rt]);
        swap(ch[rt][0], ch[rt][1]);
        rev[rt] ^= 1;
//      pushup(rt);
    }

    void replace(int rt, int val) {
        if(!rt) return;
        num[rt] = val;
        sum[rt] = val * size[rt];
        lmax[rt] = rmax[rt] = mx[rt] = max(val, sum[rt]);
        lazy[rt] = 1;
        rev[rt] = 0;
    }

    void pushdown(int rt) {
        if(!rt) return;
        if(lazy[rt]) {
            replace(ch[rt][0], num[rt]);
            replace(ch[rt][1], num[rt]);
            lazy[rt] = 0;
        }
        if(rev[rt]) {
            reverse(ch[rt][0]);
            reverse(ch[rt][1]);
            rev[rt] = 0;
        }
    }

    void down(int rt) {
        if(fa[rt]) down(fa[rt]);
        pushdown(rt);
    }

    int get(int rt) {
        return rt == ch[fa[rt]][1];
    }

    void rotate(int rt) {
        int pre = fa[rt], pa = fa[pre], dir = get(rt);
        ch[pre][dir] = ch[rt][dir ^ 1];
        fa[ch[pre][dir]] = pre;
        ch[rt][dir ^ 1] = pre;
        fa[pre] = rt;
        fa[rt] = pa;
        if(pa)
            ch[pa][ch[pa][1] == pre] = rt;
        pushup(pre);
        pushup(rt);
    }

    void splay(int rt, int tar) {
        down(rt);
        for(int pre = fa[rt]; (pre = fa[rt]) != tar; rotate(rt)) {
            if(fa[pre] != tar)
                rotate(get(rt) == get(pre) ? pre : rt);
        }
        pushup(rt);
        if(tar == 0)
            root = rt;
    }

    int Find_kth(int rt, int k) {
        pushdown(rt);
        assert(rt != 0);
        int t = size[ch[rt][0]] + 1;
        if(t == k) return rt;
        return t > k ? Find_kth(ch[rt][0], k) : Find_kth(ch[rt][1], k - t);
    }

    void erase(int rt) {
        if(!rt) return;
        stk[top++] = rt;
        erase(ch[rt][0]);
        erase(ch[rt][1]);
        clear(rt);
    }

    void Insert(int l, int cnt) {
        for(int i = 1; i <= cnt; ++i) read(a[i]);
        splay(Find_kth(root, l + 1), 0);
        splay(Find_kth(root, l + 2), root);
        pushdown(root);
        pushdown(ch[root][1]);
        build(ch[root][1], 1, cnt, ch[ch[root][1]][0]);
        pushup(ch[root][1]);
        pushup(root);
    }

    void Delete(int l, int cnt) {
        splay(Find_kth(root, l), 0);
        splay(Find_kth(ch[root][1], cnt + 1), root);
        pushdown(root);
        pushdown(ch[root][1]);
        erase(ch[ch[root][1]][0]);
        ch[ch[root][1]][0] = 0;
        pushup(ch[root][1]);
        pushup(root);
    }

    int Query(int l, int cnt) {
        splay(Find_kth(root, l), 0);
        splay(Find_kth(ch[root][1], cnt + 1), root);
        pushdown(root);
        pushdown(ch[root][1]);
        return sum[ch[ch[root][1]][0]];
    }

    void Reverse(int l, int cnt) {
        splay(Find_kth(root, l), 0);
        splay(Find_kth(ch[root][1], cnt + 1), root);
        pushdown(root);
        pushdown(ch[root][1]);
        reverse(ch[ch[root][1]][0]);
        pushup(ch[root][1]);
        pushup(root);
    }

    void Replace(int l, int cnt, int val) {
        splay(Find_kth(root, l), 0);
        splay(Find_kth(ch[root][1], cnt + 1), root);
        pushdown(root);
        pushdown(ch[root][1]);
        replace(ch[ch[root][1]][0], val);
        pushup(ch[root][1]);
        pushup(root);
    }

    void print(int rt) {
        if(!rt) 
            return;
        //cout << "RT = " << rt << endl;
        pushdown(rt);
        print(ch[rt][0]);
            // if(!first) {
            //  first = 1;
            //  printf("%d", num[rt]);
            // }
            // else
                printf(" %d", num[rt]);
        print(ch[rt][1]);
    }

}spt;

int main() {
    read(n); read(m); {
        for(int i = 1; i <= n; ++i) 
        	read(a[i]);
        a[0] = a[n + 1] = -INF;
        spt.init();
        while(m--) {
        	read(ch);
            if(ch[2] == 'X') {
                if(spt.size[spt.root] == 2)
                    puts("0");
                else
                    printf("%d\n", spt.mx[spt.root]);
            }
            else if(ch[0] == 'I') {
            	read(A); read(B);
                spt.Insert(A, B);
            }
            else if(ch[0] == 'D') {
            	read(A); read(B);
                spt.Delete(A, B);
            }
            else if(ch[0] == 'M') {
            	read(A); read(B); read(C);
                spt.Replace(A, B, C);
            }
            else if(ch[0] == 'R') {
            	read(A); read(B);
                spt.Reverse(A, B);
            }
            else {
            	read(A); read(B);
                printf("%d\n", spt.Query(A, B));
            }
        }
    }
    return 0;
}
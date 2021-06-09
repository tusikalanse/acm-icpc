#include <bits/stdc++.h>
using namespace std;

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



const int N = 2e5 + 10;

struct node {
	int val, id;
	bool operator<(const node &rhs) const {
		return val < rhs.val;
	}
}a[N];

int rnk[N], T, n, ans[N], m, sum, mn, b[N];

long long tree[N << 2];
int cnt[N << 2];

void pushup(int rt) {
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
	cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	tree[rt] = 0; cnt[rt] = 0;
	if(l == r) return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {tree[rt] += val, cnt[rt]++; return;}
	int mid = l + r >> 1;
	if(pos <= mid) update(rt << 1, l, mid, pos, val);
	else update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int query(int rt, int l, int r, long long val) {
	if(l == r) return tree[rt] <= val ? cnt[rt] : 0;
	int mid = l + r >> 1;
	if(tree[rt << 1] <= val) return cnt[rt << 1] + query(rt << 1 | 1, mid + 1, r, val - tree[rt << 1]);
	else return query(rt << 1, l, mid, val); 
}

int main() {
	read(T);
	while(T--) {
		sum = ans[0] = 0;
		read(n); read(m);
		for(int i = 1; i <= n; ++i) {
			read(a[i].val);
			b[i] = a[i].val;
			a[i].id = i;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i)
			rnk[a[i].id] = i;
		build(1, 1, n);
		for(int i = 1; i <= n; ++i) {
			ans[i] = i - 1 - query(1, 1, n, m - b[i]);
			update(1, 1, n, rnk[i], b[i]);
		}
		for(int i = 1; i <= n; ++i)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}


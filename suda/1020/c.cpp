#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m, k;
int zrs[N << 2];
long long mn[N << 2], lz[N << 2];
long long sum[N << 2];

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


void pushup(int rt) {
	zrs[rt] = zrs[rt << 1] + zrs[rt << 1 | 1];
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}

void pushdown(int rt, int l, int r) {
	if(lz[rt]) {
		int mid = l + r >> 1;
		lz[rt << 1] += lz[rt];
		lz[rt << 1 | 1] += lz[rt];
		sum[rt << 1] -= (mid - l + 1 - zrs[rt << 1]) * 1LL * lz[rt]; 
		sum[rt << 1 | 1] -= (r - mid - zrs[rt << 1 | 1]) * 1LL * lz[rt]; 
		if(mn[rt << 1])
			mn[rt << 1] -= lz[rt];
		if(mn[rt << 1 | 1])
			mn[rt << 1 | 1] -= lz[rt];
		lz[rt] = 0;
	}
}

void build(int rt, int l, int r) {
	lz[rt] = zrs[rt] = 0;
	if(l == r) {
		mn[rt] = sum[rt] = k;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

long long adjust(int rt, int l, int r) {
	if(mn[rt] > 0)
		return 0;
	if(l == r) {
		long long c = mn[rt];
		mn[rt] = sum[rt] = 0;
		zrs[rt]++;
		return c;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	long long ans = 0;
	ans += adjust(rt << 1, l, mid);
	ans += adjust(rt << 1 | 1, mid + 1, r);
	pushup(rt);
	return ans;
}

long long update(int rt, int l, int r, int L, int R, int c) {
	if(sum[rt] == 0)
		return 0;
	if(L <= l && r <= R) {
		lz[rt] += c;
		sum[rt] -= 1LL * c * (r - l + 1 - zrs[rt]);
		if(mn[rt])
			mn[rt] -= c;
		return 1LL * c * (r - l + 1 - zrs[rt]);
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	long long ans = 0;
	if(mid >= L)
		ans += update(rt << 1, l, mid, L, R, c);
	if(mid < R)
		ans += update(rt << 1 | 1, mid + 1, r, L, R, c);
	pushup(rt);
	return ans;
}

long long query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return sum[rt];
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	long long ans = 0;
	if(mid >= L)
		ans += query(rt << 1, l, mid, L, R);
	if(mid < R)
		ans += query(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

int qp(int rt, int l, int r, int pos) {
	if(l == r)
		return mn[rt];
	int mid = l + r >> 1;
	pushdown(rt, l, r);
	if(mid <= pos)
		return qp(rt << 1, l, mid, pos);
	else
		return qp(rt << 1 | 1, mid + 1, r, pos);
}

struct node {
	int l, r, c, p;
	bool operator<(const node &rhs) const {
		return p < rhs.p;
	}
}mm[N / 5];

long long ans = 0, tmp;

int main() {
	read(n); read(k); read(m);
	for(int i = 0; i < m; ++i) {
		read(mm[i].l); read(mm[i].r); read(mm[i].c); read(mm[i].p);
	}
	sort(mm, mm + m);
	build(1, 1, n);
	for(int i = 0; i < m; ++i) {
		tmp = update(1, 1, n, mm[i].l, mm[i].r, mm[i].c);
		cout << "mn[rt] = " << mn[1] << endl;
		for(int j = 1; j <= 5; ++j) {
			cout << qp(1, 1, n, j) << "MM " << endl;
			cout << query(1, 1, n, j, j) << "  J  " << endl;
		}
		tmp += adjust(1, 1, n);
		for(int j = 1; j <= 5; ++j) {
			cout << qp(1, 1, n, j) << "MM " << endl;
			cout << query(1, 1, n, j, j) << "  J  " << endl;
		}
		cout << "zrs[rt] = " << zrs[1] << endl;
		cout << "tmp = " << tmp << endl;
		ans += tmp * mm[i].p;
		if(sum[1] == 0)
			break;
	}
	printf("%lld\n", ans);
	return 0;
}
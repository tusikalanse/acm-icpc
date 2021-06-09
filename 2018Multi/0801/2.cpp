#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int mod = 1e9+7;

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


const int blk = 316;

struct node {
	int l, r, id;
	LL ans;
	bool operator<(const node &rhs) const{
		return l / blk == rhs.l / blk ? r < rhs.r : l / blk < rhs.l / blk;
	}
}lis[100010];

int n, m;
LL ans;


LL qp(LL a, LL n) {
	LL ans = 1;
	while(n) {
		if(n & 1)
			ans = a * ans % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

LL fac[100010], inv[100010];
LL res[100010];

inline void addn() {
	ans = ((2 * ans % mod - fac[n] * inv[m] % mod * inv[n - m] % mod) % mod + mod) % mod;
	n++;
}
inline void minn() {
	ans = (ans + fac[n - 1] * inv[m] % mod * inv[n - m - 1] % mod) * inv[2] % mod;
	n--;
}
inline void addm() {
	ans = (ans + fac[n] * inv[m + 1] % mod * inv[n - m - 1] % mod) % mod;
	m++;
}
inline void minm() {
	ans = ((ans - fac[n] * inv[m] % mod * inv[n - m] % mod) % mod + mod) % mod;
	m--;
}


void init() {
	fac[0] = 1;
	for(int i = 1; i <= 100000; ++i) {
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[100000] = qp(fac[100000], mod - 2);
	for(int i = 99999; ~i; --i) 
		inv[i] = inv[i + 1] * (i + 1) % mod;
	n = lis[0].l;
	m = lis[0].r;
	ans = 0;
	for(int i = 0; i <= m; ++i) {
		ans = (ans + fac[n] * inv[i] % mod * inv[n - i] % mod) % mod;
	}
}

void output(LL n) {
	if(n > 9)
		output(n / 10);
   	putchar('0' + n % 10);
}

int main() {
	int T;
	read(T);
	for(int i = 0; i < T; ++i) {
		read(lis[i].l);
		read(lis[i].r);
		lis[i].id = i;
	}
	sort(lis, lis + T);
	init();
	for(int i = 0; i < T; ++i) {
		while(lis[i].l > n) addn();
		while(lis[i].l < n) minn();
		while(lis[i].r > m) addm();
		while(lis[i].r < m) minm();
		res[lis[i].id] = ans;
	}
	for(int i = 0; i < T; ++i) {
		output(res[i]);
		puts("");
	}
	return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize ("O2") 
using namespace std;
using LL = long long;


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



const int mod = 1e9 + 7;

int t, n, now, m, u, v;
char s[5];
int cnt[12][12], vis[12], inv[10], A[10], num[1026];
LL dp[1026], ans[10];

LL qp(LL a, int n) {
	LL ans = 1;
	while(n) {
		if(n & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

inline void write(LL x) {
     if(x>9) write(x/10);
     putchar(x % 10 + '0');
}

int main() {
	A[0] = inv[0] = 1;
	for(int i = 1; i <= 5; ++i) {
		A[i] = A[i - 1] * i;
		inv[i] = qp(A[i], mod - 2);
	}
	num[1] = 1;
	for(int i = 1; (i << 1) < 1025; ++i) {
		num[i << 1] = num[i];
		num[i << 1 | 1] = 1 + num[i];
	}
	read(t);
	while(t--) {
		memset(cnt, 0, sizeof(cnt));
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		read(n);
		read(m);
		for(int ii = 1; ii <= m; ++ii) {
			memset(ans, 0, sizeof(ans));
			read(s);
			read(u);
			read(v);
			u--,v--;
			for(int p = 1; p < (1 << n); ++p) if((((1 << u) & p) && (1 << v) & p) && num[p] % 2 == 0)
			 	dp[p] -= dp[p - (1 << u) - (1 << v)] * cnt[u][v] % mod;
			if(s[0] == '+') {
				cnt[u][v]++;
			}
			else {
				cnt[u][v]--;
			}
			for(int p = 1; p < (1 << n); ++p) if((((1 << u) & p) && (1 << v) & p) && num[p] % 2 == 0) {
				dp[p] += dp[p - (1 << u) - (1 << v)] * cnt[u][v] % mod;
			}
			for(int i = 1; i < (1 << n); ++i) {
				if(num[i] % 2 == 1)
					continue;
				ans[num[i] / 2] += dp[i];
			}
			for(int i = 1; i <= n / 2; ++i) {
				write((ans[i]%mod+mod)%mod);
				putchar(" \n"[i == n / 2]);
			}
		}
	}
	return 0;
}
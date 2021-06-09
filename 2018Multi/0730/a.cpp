#include <bits/stdc++.h>
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



const int MAXN = 1e7 + 10;

int que[MAXN], head, tail, T, n, m, k, p, q, r, mod;
LL a[MAXN], A, B;

int main() {
	a[0] = 0;
	read(T);
	while(T--) {
		A = B = 0;
		read(n); read(m); read(k); read(p); read(q); read(r); read(mod);
		for(int i = 1; i <= k; ++i)
			read(a[i]);
		for(int i = k + 1; i <= n; ++i)
			a[i] = (1LL * p * a[i - 1] + 1LL * q * i + r) % mod;
		head = tail = 0;
		for(int i = 1; i <= n; ++i) {
			while(head < tail && a[que[tail - 1]] <= a[i])
				tail--;
			que[tail++] = i;
			if(i >= m) {
				while(head < tail && que[head] < i - m + 1)
					head++;
				A += (i - m + 1) ^ a[que[head]];
			} 
		}
		head = tail = 0;
		for(int i = n; i >= 1; --i) {
			while(head < tail && a[que[tail - 1]] <= a[i])
				tail--;
			que[tail++] = i;
			if(i <= n - m + 1) {
				while(head < tail && que[head] > i + m - 1)
					head++;
				B += i ^ (tail - head);
			}
		}
		printf("%lld %lld\n", A, B);
	}
	return 0;
}
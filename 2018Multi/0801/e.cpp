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



int a[110], T, n, q, X0, Y0, X1, Y1, X, Y, u, v;
LL ans, tot, len, tmp, tx, ty;

inline int val(int i, int j) {
	return a[(i + 1LL * (i + j)*(i+j+1)/2)%n];
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		tot = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			tot += a[i];
		}
		tot *= n;
		if(n & 1) {
			len = n;
		}
		else {
			tot *= 4;
			len = 2 * n;
		}
		scanf("%d", &q);
		while(q--) {
			scanf("%d%d%d%d", &X0, &Y0, &X1, &Y1);
			u = (X1 - X0 + 1) / len; 
			v = (Y1 - Y0 + 1) / len; 
			X = X0 + u * len - 1;
			Y = Y0 + v * len - 1;
			tx = ty = tmp = 0;
			ans = 1LL * u * v * tot;
			for(int i = X + 1; i <= X1; ++i) {
				for(int j = Y + 1; j <= Y1; ++j) {
					tmp += val(i, j);
				}
			}
			for(int i = X0; i <= X0 + len - 1; ++i) {
				for(int j = Y + 1; j <= Y1; ++j)
					tx += val(i, j);
			}
			for(int i = X + 1; i <= X1; ++i) {
				for(int j = Y0; j <= Y0 + len - 1; ++j)
					ty += val(i, j);
			}
			ans += tmp + tx * u + ty * v;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
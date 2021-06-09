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

const int N = 1e6 + 10;
int T, n, m, a[N], tot, now, l, r, lastans, op, x;

struct Base {
    int a[30], pos[30];
    int m;
    Base() {
        memset(a, 0, sizeof(a));
        memset(pos, 0, sizeof(pos));
        m = 0;
    }
    bool insert(int x, int p) {
        for(int i = 29; ~i; --i) {
            if((x >> i) & 1) {
                if(a[i] == 0) {
                    a[i] = x;
                    pos[i] = p;
                    m++;
                    return 1;
                }
                else if(pos[i] < p) {
                	swap(pos[i], p);
                	swap(a[i], x);
                	x ^= a[i];
                }
                else {
                    x ^= a[i];
                }
            }
        }
        return 0;
    }
    int query(int x, int l) {
    	for(int i = 29; ~i; --i) {
    		if(pos[i] >= l)
	    		x = max(x, x ^ a[i]);
    	}
    	return x;
    }
}f[N];

void output(int x) {
	if(x >= 10)
		output(x / 10);
	putchar('0' + x % 10);
}

int main() {
	read(T);
	while(T--) {
		read(n); read(m);
		for(int i = 1; i <= n; ++i) {
			read(a[i]);
			f[i] = f[i - 1];
			f[i].insert(a[i], i);
		}
		lastans = 0;
		now = n;
		for(int i = 1; i <= m; ++i) {
			read(op);
			if(op == 0) {
				read(l); read(r);
				l ^= lastans;
				r ^= lastans;
				l %= now;
				r %= now;
				l++, r++;
				if(l > r)
					swap(l, r);
				lastans = f[r].query(0, l);
				output(lastans);
				putchar('\n');
			}
			else {
				now++;
				read(x);
				x ^= lastans;
				a[now] = x;
				f[now] = f[now - 1];
				f[now].insert(a[now], now);
			}
		}
	}
	return 0;
}
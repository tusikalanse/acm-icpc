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


inline void write(int x) {
     if(x>9) write(x/10);
     putchar(x % 10 + '0');
}

const int INF=0xfffffff ;
struct Point{
    int x,y, id;
    bool operator<(const Point &rhs) const {
    	return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
    bool operator>(const Point &rhs) const {
    	return rhs < *this;
    }
    bool operator!=(const Point &rhs) const {
    	return *this < rhs || *this > rhs;
    }
    bool operator==(const Point &rhs) const {
    	return !(*this != rhs);
    }
} ;
Point p[200005],s[200005] ;
int top;
LL direction(Point p1,Point p2,Point p3) {
    return 1LL * (p3.x-p1.x)*(p2.y-p1.y)-1LL * (p2.x-p1.x)*(p3.y-p1.y) ;
}
bool cmp(const Point &a, const Point &b) {
	return a == b ? a.id < b.id : a < b;
}
void Graham(int n) {
    top = 0;
    for(int i=0; i < n; i++) {
	    while(top >= 2) {
        	LL d = direction(s[top-2],s[top-1],p[i]);
        	if(d < 0 || (d == 0 && p[i].id < s[top-1].id))
        	  	top--;
        	 else
        	 	break;
        }
        s[top++] = p[i];
    }
    for(int i = 0; i < top; ++i) {
    	if(i != 0)
    		putchar(' ');
    	write(s[i].id);
    }
    puts("");
}

int T, n, x, y;
int main() {
	read(T);
	while(T--) {
		read(n);
		for(int i = 0; i < n; ++i) {
			read(p[i].x);
			read(p[i].y);
			p[i].id = i + 1;
		}
		sort(p, p + n, cmp);
		n = unique(p, p + n) - p;
		Graham(n);
	}
	return 0;
}
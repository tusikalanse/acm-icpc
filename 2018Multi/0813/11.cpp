#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3;
int T, n, k, b[5][N], vis[5][N], ab[5], p[5], cnt;

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



struct node {
	int a, id;
	bool operator<(const node &rhs) const {
		return a < rhs.a;
	}
}a[5][N];

int main() {
	read(T);
	while(T--) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		memset(p, 0, sizeof(p));
		read(n);
		read(k);
		for(int i = 0; i < k; ++i)
			read(ab[i]);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < k; ++j) {
				read(a[j][i].a);
				a[j][i].id = i;
			}
			for(int j = 0; j < k; ++j)
				read(b[j][i]);
		}
		for(int i = 0; i < k; ++i)
			sort(a[i], a[i] + n);
		queue<int> Q;
		do {
			while(!Q.empty()) {
				int u = Q.front(); Q.pop();
				for(int i = 0; i < k; ++i) ab[i] += b[i][u];
			}
			for(int i = 0; i < k; ++i) {
				for(; p[i] < n && a[i][p[i]].a <= ab[i]; ++p[i]) {
					int id = a[i][p[i]].id;
					vis[i][id] = 1;
					int tot = 1;
					for(int _ = 0; _ < k; ++_) tot *= vis[_][id];
					if(tot) Q.push(id), cnt++;
				}
			}
		} while(!Q.empty());
		printf("%d\n", cnt);
		for(int i = 0; i < k; ++i)
			printf("%d%c", ab[i], " \n"[i == k - 1]);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

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
        if (pend==p1){IOerror=1;return -1;}    
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




const int MAXN = 3e5 + 10;
int n, x, y;

int fa[MAXN << 1], head[MAXN << 1], vis[MAXN << 1], nxt[MAXN << 1], pnt[MAXN << 1], cnt = 0;

void add(int x, int y) {
	nxt[cnt] = head[x];
	pnt[cnt] = y;
	head[x] = cnt++;
}

int dfs(int rt) {
	vis[rt] = 1;
	int cnt = 1;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] == 0)
			cnt += dfs(j);
	}
	return cnt;
}

void bfs() {
	vis[x] = 1;
	fa[x] = -1;
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; ~i; i = nxt[i]) {
			int j = pnt[i];
			if(j == y) {
				fa[y] = u;
				goto otty;
			}
			if(!vis[j]) {
				vis[j] = 1;
				fa[j] = u;
				q.push(j);
			}
		}
	}
	otty:;
	int t = fa[y];
	memset(vis, 0, sizeof(vis));
	vis[x] = vis[y] = 1;
	if(t != x)
		dfs(t);
}


int main() {
	int a, b;
	memset(head, -1, sizeof(head));
	read(n);
	read(x);
	read(y);
	for(int i = 1; i < n; ++i) {
		read(a);
		read(b);
		add(a, b);
		add(b, a);
	}
	memset(vis, 0, sizeof(vis));
	bfs();
	int p = dfs(x), q = dfs(y);
	printf("%lld\n", 1LL * n * (n - 1) - 1LL * p * q);
	return 0;
}
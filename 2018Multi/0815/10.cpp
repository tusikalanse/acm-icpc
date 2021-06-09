#include <bits/stdc++.h>
#define LL long long
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



const int N = 1e5 + 10;
const int MAXN = 1e5 + 10;

int n, m, T;
int que[N], pre[N], len[N], head, tail, vis[N], cnt[N], tmp;

int a[MAXN], A, B, b[MAXN], mmax, id;

struct SplayTree {
	int ch[MAXN][2], fa[MAXN], key[MAXN], sz, root, num[MAXN], mx[MAXN], size[MAXN];

	void clear(int rt) {
		ch[rt][0] = ch[rt][1] = fa[rt] = key[rt] = mx[rt] = num[rt] = size[rt] = 0;
	}

	void newnode(int pre, int val, int ky, int &rt) {
		rt = ++sz;
		size[rt] = 1;
		fa[rt] = pre;
		key[rt] = val;
		mx[rt] = num[rt] = ky;
		ch[rt][0] = ch[rt][1] = 0;
	}

	void pushup(int rt) {
		size[rt] = 1 + size[ch[rt][0]] + size[ch[rt][1]];
		mx[rt] = num[rt];
		if(ch[rt][0])
			mx[rt] = max(mx[rt], mx[ch[rt][0]]);
		if(ch[rt][1])
			mx[rt] = max(mx[rt], mx[ch[rt][1]]);
	}

	void build(int pre, int l, int r, int &rt) {
		if(l > r) return;
		int mid = l + r >> 1;
		newnode(pre, a[mid], b[mid], rt);
		build(rt, l, mid - 1, ch[rt][0]);
		build(rt, mid + 1, r, ch[rt][1]);
		pushup(rt);
	}

	void init() {
		root = sz = 0;
		ch[root][0] = ch[root][1] = fa[root] = size[root] = 0;
		build(0, 1, n, root);
		insert(0, 0);
		insert(n + 1, 0);
		pushup(root);
	}

	void pushdown(int rt) {}

	int get(int x) {
		return x == ch[fa[x]][1];
	}

	void rotate(int x) {
		int pre = fa[x], pa = fa[pre], which = get(x);
		ch[pre][which] = ch[x][which ^ 1];
		fa[ch[pre][which]] = pre;
		ch[x][which ^ 1] = pre;
		fa[pre] = x;		
		fa[x] = pa;
		if(pa)
			ch[pa][ch[pa][1] == pre] = x;
		pushup(pre);
		pushup(x);
	}

	void splay(int x, int tar) {
		pushdown(x);
		for(int pre = fa[x]; (pre = fa[x]) != tar; rotate(x)) {
			if(fa[pre] != tar)
				pushdown(fa[pre]), pushdown(pre), pushdown(x), rotate(get(x) == get(pre) ? pre : x);
			else
				pushdown(pre), pushdown(x);
		}
		pushup(x);
		if(tar == 0)
			root = x;
	}

	int Find_min(int rt) {
		pushdown(rt);
		return ch[rt][0] ? Find_min(ch[rt][0]) : (splay(rt, 0), rt);
	}

	int Find_max(int rt) {
		pushdown(rt);
		return ch[rt][1] ? Find_max(ch[rt][1]) : (splay(rt, 0), rt);
	}

	int Find_kth(int rt, int k) {
		pushdown(rt);
		int t = size[ch[rt][0]] + 1;
		if(t == k) {
	//		splay(rt, 0);
			return rt;
		}
		return t > k ? Find_kth(ch[rt][0], k) : Find_kth(ch[rt][1], k - t);
	}

	int Find(int rt, int val) {
		if(mx[rt] <= val)
			return -1;
		if(ch[rt][0] && mx[ch[rt][0]] > val)
			return Find(ch[rt][0], val);
		if(num[rt] > val)
			return rt;
		return Find(ch[rt][1], val);
	}

	void del() {
		int old = root;
		if(!ch[root][0]) {
			root = ch[old][1];
			fa[root] = 0;
		}
		else {
			Find_max(ch[root][0]);
			ch[root][1] = ch[old][1];
			fa[old] = root;
		}
		clear(old);
	}

	void update(int rt, int val) {
		num[rt] = val;
		mx[rt] = max(mx[rt], val);
	}

	void insert(int v, int val) {
		int rt = root;
		if(root == 0) 
			newnode(0, v, val, root);
		else {
			while(ch[rt][key[rt] < v])
				rt = ch[rt][key[rt] < v];
			newnode(rt, v, val, ch[rt][key[rt] < v]);
			splay(ch[rt][key[rt] < v], 0);
		}
	}
}spt;

int main() {
	read(T);
	while(T--) {
		memset(vis, 0, sizeof(vis));
		read(n);
		read(m);
		for(int i = 1; i <= n; ++i) {
			read(b[i]);
			a[i] = i;
		}
		spt.init();
		id = 0;
		mmax = 0;
		tmp = 0;
		for(int i = 1; i <= n; ++i) {
			pre[i] = id;
			if(mmax < b[i]) {
				mmax = b[i]; 
				id = i;
				vis[i] = 1;
				tmp++;
			}
			cnt[i] = tmp;
		}
		head = tail = 0;
		len[n] = 1;
		que[tail++] = n;
		for(int i = n - 1; i > 0; --i) {
			while(head < tail && b[que[tail - 1]] <= b[i])
				tail--;
			que[tail++] = i;
			len[i] = tail - head;
		}
		while(m--) {
			read(A);
			read(B);
			if(!vis[A]) {
				if(B <= b[pre[A]]) {
					printf("%d\n", len[1]);
				}
				else {
					spt.splay(spt.Find_kth(spt.root, A + 1), 0);
					int id = spt.Find(spt.ch[spt.root][1], B);
					if(id == -1) {
						printf("%d\n", 1 + cnt[A]);
					}
					else 
						printf("%d\n", 1 + cnt[A] + len[spt.key[id]]);
				}
			}
			else {
				if(B > b[pre[A]]) {
					spt.splay(spt.Find_kth(spt.root, A + 1), 0);
					int id = spt.Find(spt.ch[spt.root][1], B);
					if(id == -1) {
						printf("%d\n", cnt[A]);
					}
					else
						printf("%d\n", cnt[A] + len[spt.key[id]]);
				}
				else {
					spt.splay(spt.Find_kth(spt.root, A + 1), 0);
					int id = spt.Find(spt.ch[spt.root][1], b[pre[A]]);
					if(id == -1) {
						printf("%d\n", cnt[pre[A]]);
					}
					else
						printf("%d\n", cnt[pre[A]] + len[spt.key[id]]);
				}
			}
		}
	}
	return 0;
}


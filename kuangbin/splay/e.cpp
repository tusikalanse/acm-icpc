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



const int MAXN = 1e6 + 10;
int n, x;
int lis[MAXN];

unordered_map<int, int> cnt;
struct node {
	double val;
	int id;
	bool operator<(const node &rhs) const {
		return val < rhs.val;
	}
}a[MAXN];

struct SplayTree {
	int ch[MAXN][2], fa[MAXN], key[MAXN], sz, root, size[MAXN], rev[MAXN];

	void clear(int rt) {
		rev[rt] = ch[rt][0] = ch[rt][1] = fa[rt] = key[rt] = size[rt] = 0;
	}

	void newnode(int pre, int val, int &rt) {
		rt = ++sz;
		lis[val] = rt;
		fa[rt] = pre;
		key[rt] = val;
		rev[rt] = 0;
		ch[rt][0] = ch[rt][1] = 0;
		size[rt] = 1;
	}

	void pushup(int rt) {
		size[rt] = 1 + size[ch[rt][0]] + size[ch[rt][1]];
	}

	void build(int pre, int l, int r, int &rt) {
		if(l > r) return;
		int mid = l + r >> 1;
		newnode(pre, mid, rt);
		build(rt, l, mid - 1, ch[rt][0]);
		build(rt, mid + 1, r, ch[rt][1]);
		pushup(rt);
	}

	void init() {
		root = sz = 0;
		rev[root] = ch[root][0] = ch[root][1] = fa[root] = size[root] = 0;
		build(0, 1, n, root);
		pushup(root);
	}

	void update_rev(int rt) {
		if(!rt) return;
		swap(ch[rt][0], ch[rt][1]);
		rev[rt] ^= 1;
	}

	void pushdown(int rt) {
		if(rev[rt]) {
			update_rev(ch[rt][0]);
			update_rev(ch[rt][1]);
			rev[rt] = 0;
		}
	}

	int get(int x) {
		return x == ch[fa[x]][1];
	}

	void rotate(int x) {
		int pre = fa[x], pa = fa[pre], which = get(x);
		pushdown(pre);
		pushdown(x);
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
			splay(rt, 0);
			return rt;
		}
		return t > k ? Find_kth(ch[rt][0], k) : Find_kth(ch[rt][1], k - t);
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
			fa[ch[old][1]] = root;
			fa[root] = 0;
			pushup(root);
		}
		clear(old);
	}

	void insert(int v) {
		int rt = root;
		if(root == 0) 
			newnode(0, v, root);
		else {
			while(ch[rt][key[rt] < v])
				rt = ch[rt][key[rt] < v];
			newnode(rt, v, ch[rt][key[rt] < v]);
			splay(ch[rt][key[rt] < v], 0);
		}
	}
}spt;

int main() {
	while(1) {
		read(n);
		if(n == 0)
			break;
		spt.init();
		cnt.clear();
		for(int i = 1; i <= n; ++i) {
			read(x);
			a[i].val = x + 1e-5 * cnt[x];
			cnt[x]++;
			a[i].id = i;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i < n; ++i) {
			spt.splay(lis[a[i].id], 0);
			spt.update_rev(spt.ch[spt.root][0]);
			printf("%d ", spt.size[spt.ch[spt.root][0]] + i);
			spt.del();
		}
		printf("%d\n", n);
	}
	return 0;
}
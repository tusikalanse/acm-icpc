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

int T, n, q;
int in[N], out[N];
vector<int> vec;
long long rem, k;
int fa[N], sz[N], tot;
multiset<int> s;

struct node {
	int x;
	long long a, b;
}NN[N << 1];

long long sum[N << 3], sum2[N << 3];
int num[N << 3];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	sum2[rt] = sum2[rt << 1] + sum2[rt << 1 | 1];
	num[rt] = num[rt << 1] + num[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = num[rt] = sum2[rt] = (l <= n);
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == pos) {
		sum[rt] = val;
		sum2[rt] = sum[rt] * sum[rt];
		num[rt] = (val != 0);
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite1(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy) {
		fa[fy] = fx;
		s.erase(s.find(sz[fx]));
		s.erase(s.find(sz[fy]));
		rem += 1LL * sz[fx] * sz[fy] - 1;
		sz[fx] += sz[fy];
		s.insert(sz[fx]);
		vec.push_back(sz[fx]);
	}
	else
		rem--;
}

void unite2(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy) {
		fa[fy] = fx;
		s.erase(s.find(sz[fx]));
		s.erase(s.find(sz[fy]));
		update(1, 1, tot, out[sz[fx]]++, 0);
		update(1, 1, tot, out[sz[fy]]++, 0);
		rem += 1LL * sz[fx] * sz[fy] - 1;
		sz[fx] += sz[fy];
		s.insert(sz[fx]);
		update(1, 1, tot, in[sz[fx]]++, sz[fx]);
	}
	else
		rem--;
}

int get_min() {
	return max(1LL, (long long)s.size() - k);
}

int get(int rt, int l, int r, long long s, long long s2, int n) {
	if(l == r) 
		return n + num[rt];
	int mid = l + r >> 1, nn = num[rt << 1 | 1];
	long long ss = sum[rt << 1 | 1], ss2 = sum2[rt << 1 | 1];
	if(((s + ss) * (s + ss) - (s2 + ss2)) / 2 >= k)
		return get(rt << 1 | 1, mid + 1, r, s, s2, n);
	else
		return get(rt << 1, l, mid, s + ss, s2 + ss2, n + nn);
}

int get_max() {
	k -= rem;
	if(k <= 0)
		return s.size();
	return (int)s.size() - get(1, 1, tot, 0, 0, 0) + 1;
}


void output(int x) {
	if(x > 9)
		output(x / 10);
	putchar('0' + x % 10);
}

int main() {
	read(T);
	while(T--) {
		s.clear();
		vec.clear();
		rem = 0;
		read(n);
		read(q);
		for(int i = 1; i <= n; ++i) {
			fa[i] = i;
			sz[i] = 1;
			in[i] = out[i] = 0;
			s.insert(1);
			vec.push_back(1);
		}
		for(int i = 1; i <= q; ++i) {
			read(NN[i].x);
			if(NN[i].x == 2) {
				read(NN[i].a);
			}
			else {
				read(NN[i].a);
				read(NN[i].b);
				unite1(NN[i].a, NN[i].b);
			}
		}
		sort(vec.begin(), vec.end());
		tot = vec.size();
		for(int i = 0; i < tot; ++i) {
			if(in[vec[i]] == 0)
				in[vec[i]] = out[vec[i]] = i + 1;
		}
		rem = 0;
		s.clear();
		for(int i = 1; i <= n; ++i) {
			fa[i] = i;
			sz[i] = 1;
			s.insert(1);
		}
		build(1, 1, tot);
		for(int i = 1; i <= q; ++i) {
			if(NN[i].x == 1)
				unite2(NN[i].a, NN[i].b);
			else {
				k = NN[i].a;
				output(get_min());
				putchar(' ');
				output(get_max());
				putchar('\n');
			}
		}
	}
	return 0;
}
#2017杭电多校第一场

[Gym 链接](https://codeforces.com/gym/102253)

hdu6033-6044

## A. Add More Zero

每次询问给定一个$n$，要求输出$2^n-1$的十进制位数减一

直接输出$(int)(n*log10(2))$即可

## B. Balala Power!

'a'-'z'26个小写字母个代表0-25这些数中的一个（互不相同），你有$n$个只含小写字母的字符串，你要安排'a'-'z'每个字母代表的数使得这些字符串代表的26进制数的总和最大且不含前导0

可以将26个字母每个字母的出现次数统计出来（出现次数可以用高精度26进制数来存储，然后直接对vector排序就好了）需要注意的是前导0需要单独处理，复杂度$O(T26n\log(26))$

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int n, cas, l, vis[26];
long long ans;
vector<int> g[26];
char s[N];

int main() {
	while(~scanf("%d", &n)) {
		ans = 0;
		for(int i = 0; i < 26; ++i) {
			g[i].clear();
			g[i].resize(N);
			vis[i] = 0;
		}
		while(n--) {
			scanf("%s", s);
			l = strlen(s);
			for(int i = 0; i < l; ++i) 
				g[s[i] - 'a'][l - i - 1]++;
			if(l != 1)
				vis[s[0] - 'a'] = 1;
		}
		for(int i = 0; i < 26; ++i) {
			for(int j = 0; j < N - 1; ++j) {
				g[i][j + 1] += g[i][j] / 26;
				g[i][j] %= 26;
			}
			reverse(g[i].begin(), g[i].end());
		}
		int zero = -1;
		for(int i = 0; i < 26; ++i) if(!vis[i]) {
			if(zero == -1 || g[i] < g[zero])
				zero = i;
		}
		swap(g[0], g[zero]);
		sort(g + 1, g + 26);
		for(int i = 1; i < 26; ++i) 
			reverse(g[i].begin(), g[i].end());
		for(int i = 1; i < 26; ++i) {
			long long base = i;
			for(int j = 0; j < N; ++j) {
				ans = (ans + base * g[i][j]) % mod;
				base = base * 26 % mod; 
			}
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}
```

## C. Colorful Tree

有一个n个结点的树，每个结点有颜色，定义路径的权值为路径上的不同颜色数量，求所有路径的权值和

反向考虑，对于每一种颜色考虑哪些路径这个颜色没有贡献，显然要求出不含这个颜色的连通块大小，那么树型dp即可，需要注意本题不能每个节点开map来存储，，否则会TLE,需要在dfs的过程中先行存储dfs之前的信息再做修改，这样所有颜色信息可以用一个数组来存储，复杂度$O(Tn)$

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> G[N];
int n, c[N], cas, vis[N], sz[N], cnt, sum[N];
long long ans;

long long gao(int n) {return 1LL * n * (n - 1) / 2;}

void dfs(int rt, int fa) {
	sz[rt] = 1;
	int tot = 0;
	for(auto i: G[rt]) {
		if(i == fa) continue;
		int last = sum[c[rt]];
		dfs(i, rt);
		sz[rt] += sz[i];
		int add = sum[c[rt]] - last;
		ans -= gao(sz[i] - add);
		tot += sz[i] - add;
	}
	sum[c[rt]] += tot + 1;
	if(rt == 1) {
		for(int col = 1; col <= n; ++col) {
			if(!vis[col]) continue;
			ans -= gao(sz[rt] - sum[col]);
		}
	}
}

int main() {
	while(~scanf("%d", &n)) {
		cnt = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &c[i]);
			vis[c[i]] = 1;
		}
		for(int i = 1; i <= n; ++i)
			cnt += vis[i];
		for(int i = 1; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		ans = 1LL * cnt * n * (n - 1) / 2;
		dfs(1, 0);
		printf("Case #%d: %lld\n", ++cas, ans);
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			sum[c[i]] = 0;
			vis[c[i]] = 0;
		}
	}
	return 0;
}
```

## F. Function

给你两个长度分别为n, m的数组a, b, a是0-n-1的一个排列, b是0-m-1的一个排列，你要求一个函数$f$, 使得$f(i) = b_{f(a_i)}$, 问你有多少种这样的$f$

首先$i->a[i]$建边，那么a一定是若干个环（可能有自环），同理b也是，找一找规律可以看出对于a中的一个环长为$x$的环，它的每个点的值必须是b上的一个环长为$y$的值,且$y$是$x$的因子，对于该环$x$方案数加上$y$，然后每个环之间方案数乘起来就好了，复杂度$O(Tn)$(看看代码想一想为什么，保证没有快速幂的那个$\log$)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;

long long qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n & 1) 
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int n, m, a[N], b[N], vis[N], cas = 0;

int cnta[N], cntb[N], ans;

int main() {
	while(~scanf("%d%d", &n, &m)) {
		ans = 1;
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for(int i = 0; i < m; ++i) scanf("%d", &b[i]);
		memset(cnta, 0, sizeof(int) * (n + 8));
		memset(cntb, 0, sizeof(int) * (m + 8));	
		memset(vis, 0, sizeof(int) * n);
		for(int i = 0; i < n; ++i) {
			if(vis[i]) continue;
			vis[i] = 1;
			int cnt = 1, p = a[i];
			while(p != i) {
				cnt++;
				vis[p] = 1;
				p = a[p];
			}
			cnta[cnt]++;
		}
		memset(vis, 0, sizeof(int) * m);
		for(int i = 0; i < m; ++i) {
			if(vis[i]) continue;
			vis[i] = 1;
			int cnt = 1, p = b[i];
			while(p != i) {
				cnt++;
				vis[p] = 1;
				p = b[p];
			}
			cntb[cnt]++;
		}
		for(int i = 1; i <= n; ++i) {
			if(!cnta[i]) continue;
			int tot = 0;
			for(int j = 1; j <= i; ++j) {
				if(i % j == 0) 
					tot += j * cntb[j];
			}
			ans = 1LL * ans * qp(tot, cnta[i]) % mod;
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
```

## H. Hints of sd0061

你有1e7个数（由数据生成器生成），$m$次询问$b_{1..m}$，每次询问第$b_i+1$小的是哪个，其中$m\le100$,且保证$b_i+b_j\le b_k\ if\ b_i\neq b_j,b_i\lt b_k, b_j \lt b_k $

首先注意到$b$的限制，这保证了不同的$b$至多只有$\log(1e7)$这么多个（斐波那契数列），然后考虑库函数$nth\_element$,对询问进行从大到小处理，可以有效降低复杂度，复杂度$O(Tn)$

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int n, m, cas = 0;
unsigned a[N], A, B, C;
unsigned ans[110];
struct qu {
	int b, id;
	bool operator<(const qu &rhs) const {
		return b < rhs.b;
	}
}q[110];

unsigned x = A, y = B, z = C;
unsigned rng61() {
	unsigned t;
	x = x ^ (x << 16);
	x = x ^ (x >> 5);
	x = x ^ (x << 1);
	t = x;
	x = y;
	y = z;
	z = (t ^ x) ^ y;
	return z;
}

int main() {
	while(~scanf("%d%d%u%u%u", &n, &m, &A, &B, &C)) {
		x = A; y = B; z = C;
		for(int i = 0; i < n; ++i) {
			a[i] = rng61();
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%d", &q[i].b);
			q[i].id = i;
		}
		sort(q + 1, q + m + 1);
		q[m + 1].b = n - 1; q[m + 1].id = 0;
		nth_element(a, a + n - 1, a + n);
		ans[0] = a[n - 1];
		for(int i = m; i; --i) {
			if(q[i].b == q[i + 1].b) {
				ans[q[i].id] = ans[q[i + 1].id];
				continue;
			}
			nth_element(a, a + q[i].b, a + q[i + 1].b);
			ans[q[i].id] = a[q[i].b];
		}
		printf("Case #%d:", ++cas);
		for(int i = 1; i <= m; ++i) {
			printf(" %u", ans[i]);
		}
		puts("");
	}
	return 0;
}
```

## I. I curse myself

给你一颗$n$个点$m$条边仙人掌，定义$V(k)$为该仙人掌的第$k$小生成树的权值(若生成树数量小于$k$则为0)，求$$\sum\limits_{k=1}^{k=K}kV(k)$$, $2\le n\le 1000, n-1\le m\le2n-3, 1\le K\le1e5$

首先仙人掌的最小生成树是每一个环去掉一条边，问题变成了有若干个集合，每个集合取一个数求前$K$大的和分别是啥，这是一个经典问题（...我怎么不知道），可以证明单组样例的复杂度为$O(mK)$，考虑如下合并算法:

合并两个集合(数组)A, B, 将A从大到小排列，向大根堆中加入$A[0]+B[j]$, 然后每次取出一个数$A[i]+B[j]$, 向堆中加入$A[i+1]+B[j]$,直到堆空或者取了$K$个为止，复杂度为$O(K\log(B.size))$, 可以让每次合并是$B$是新找到的环，那么总复杂度为$O(K\sum\log c_i), c_i$为环长，然后经过数学推导可得出复杂度为$O(mK)$, ps:如果合并时让$B$是之前已合并的集合那么复杂度就是$O(mK\log(K))$了，会TLE

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

vector<int> tmp, now;
vector<pair<int, int>> G[N];
int fa[N], dep[N], val[N], n, m, k, cas;
long long tot, ans;

struct node {
	int val, x, y;
	bool operator<(const node &rhs) const {
		return val < rhs.val;
	}
};

void merge(vector<int> &now, vector<int> &rhs) {
	sort(now.begin(), now.end(), greater<int>());
	sort(rhs.begin(), rhs.end(), greater<int>());
	tmp.clear();
	priority_queue<node> pq;
	for(int i = 0; i < rhs.size(); ++i) {
		pq.push((node){now[0] + rhs[i], 0, i});
	}
	while(tmp.size() < k && !pq.empty()) {
		node u = pq.top();
		pq.pop();
		tmp.push_back(u.val);
		if(u.x + 1 < now.size()) {
			pq.push((node){now[u.x + 1] + rhs[u.y], u.x + 1, u.y});
		}
	}
	now = tmp;
}

void dfs(int rt, int pre, int depth, int value) {
	dep[rt] = depth;
	fa[rt] = pre;
	val[rt] = value;
	for(int i = 0; i < G[rt].size(); ++i) {
		pair<int, int> u = G[rt][i], tmp;
		if(u.first == pre) continue;
		if(dep[u.first]) {
			if(dep[u.first] < dep[rt]) {
				vector<int> v;
				v.push_back(u.second);
				tmp = make_pair(rt, val[rt]);
				while(tmp.first != u.first) {
					v.push_back(tmp.second);
					tmp = make_pair(fa[tmp.first], val[fa[tmp.first]]);
				}
				merge(now, v);
			}
			continue;
		}
		dfs(u.first, rt, depth + 1, u.second);
	}
}

int main() {
	now.reserve(1000001); tmp.reserve(1000001);
	while(~scanf("%d%d", &n, &m)) {
		tot = 0;
		for(int i = 1; i <= m; ++i) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(make_pair(b, c));
			G[b].push_back(make_pair(a, c));
			tot += c;
		}
		now.clear();
		now.push_back(0);
		scanf("%d", &k);
		for(int i = 1; i <= n; ++i) {
			if(!dep[i])
				dfs(i, 0, 1, 0);
		}
		ans = 0;
		for(int i = 0; i < now.size(); ++i)
			ans += 1LL * (i + 1) * (tot - now[i]);
		printf("Case #%d: %lld\n", ++cas, ans % (1LL << 32));
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			dep[i] = 0;
		}
	}
	return 0;
}

```

## K. KazaQ's socks

$n$双袜子，一开始每双都是干净的，每天早上会选一双编号最小的干净的穿，若是有一天晚上发现脏袜子数量等于$n-1$则会洗了这些袜子，第二天晾干，第三天早上可用，给定$k$，问第$k$天穿的袜子编号

打表发现规律是$1,2,3,....,n$然后$1,2,3...,n-2,n-1,1,2,3....n-2,n$开始循环，循环节长度为$2*(n-1)$,直接求即可

## L. Limited Permutation

你有一个1-n的排列p, 有两个长为n的数组l, r,满足$\min\limits_{j = L}^Rp_j=p_i\ iff\ l_i\le L\le i\le R\le r_i$,求满足条件的排列$p$的数量$1\le n\le 1e6$

分析一下条件，意为$p_i$是$p_{l_i},p_{l_i+1},...p_{r_i}$这些数中最小值且$p_i\gt p_{l_i-1}, p_i\gt p_{r_i+1}$

考虑dfs(l ,r), 意为l到r放1 ~ r-l+1的排列方案数，首先这些数中一定有且仅有一个数$i$满足$l_i=l, r_i=r$(若没有或有多个则无解)，表示这些数中的最小值，然后它将$(l, r)$划分为两个区间$(l, i-1)$和$(i+1, r)$, 方案数要乘上$C(r-l, i-l)$,需要注意无解情况的判断，复杂度$O(Tn\log(n))$

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

int fac[N], facinv[N]; 
int n, cas, l[N], r[N], ans;

long long qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n & 1) 
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

void init() {
	fac[0] = fac[1] = 1;
	for(int i = 2; i < N; ++i)
		fac[i] = 1LL * i * fac[i - 1] % mod;
	facinv[N - 1] = qp(fac[N - 1], mod - 2);
	for(int i = N - 2; ~i; --i) 
		facinv[i] = 1LL * facinv[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
	return 1LL * fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

vector<pair<int, int>> mp[N];

int find(int l, int r) {
	vector<pair<int, int>>::iterator s = lower_bound(mp[l].begin(), mp[l].end(), make_pair(r, 0));
	if(s == mp[l].end() || s->first != r) return 0;
	return s->second;
}

void dfs(int l, int r) {
	int pos = find(l, r);
	if(pos == 0) {
		ans = 0;
		return;
	}
	if(l == r) {
		if(pos != l) ans = 0;
		return;
	}
	if(pos == l) 
		dfs(l + 1, r);
	else if(pos == r)
		dfs(l, r - 1);
	else {
		ans = 1LL * ans * C(r - l, pos - l) % mod; 
		dfs(l, pos - 1);
		dfs(pos + 1, r);
	}
}

int main() {
	init();
	while(~scanf("%d", &n)) {
		ans = 1;
		for(int i = 1; i <= n; ++i) scanf("%d", &l[i]);
		for(int i = 1; i <= n; ++i) scanf("%d", &r[i]);
		for(int i = 1; i <= n; ++i) {
			mp[l[i]].emplace_back(r[i], i);
		}
		for(int i = 1; i <= n; ++i) sort(mp[i].begin(), mp[i].end());
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j + 1 < mp[i].size(); ++j)
				if(mp[i][j].first == mp[i][j + 1].first)
					ans = 0;
		}
		if(ans)
			dfs(1, n);
		printf("Case #%d: %d\n", ++cas, ans);
		for(int i = 1; i <= n; ++i) mp[i].clear();
	}
	return 0;
}
```


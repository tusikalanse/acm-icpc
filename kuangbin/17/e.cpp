#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int MAXN = 105;
const int mod = 100000;
const int KIND = 4;

char s[20];

struct Mat {
	int n;
	long long mat[MAXN][MAXN];
	Mat(int nnn, bool e = false)  {
		n = nnn;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				mat[i][j] = 0;
		if(e) {
			for(int i = 0; i < n; ++i)
				mat[i][i] = 1;
		}
	}
	Mat operator*(const Mat &rhs) {
		Mat res(rhs.n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) 
				for(int k = 0; k < n; ++k) {
					res.mat[i][j] = (res.mat[i][j] + mat[i][k] * rhs.mat[k][j]) % mod;
				}
		return res;
	}
	void print() {
		cout << n << endl;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				printf("%lld ", mat[i][j]);
			puts("");
		}
	}
};

long long Mat_qp(Mat &a, int n) {
	Mat res(a.n, 1);
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	long long ans = 0;
	for(int i = 0; i < res.n; ++i) 
		ans = (ans + res.mat[0][i]) % mod;
	return ans;
}

inline int mp(char ch) {
	if(ch == 'A') return 0;
	if(ch == 'T') return 1;
	if(ch == 'G') return 2;
	if(ch == 'C') return 3;
	return -1;
}

struct AC_automation {
	int root, L;
	int nxt[MAXN][KIND], fail[MAXN], end[MAXN];
	AC_automation() : L(0) {}
	void init() {
		L = 0;
		root = newnode();
	}
	int newnode() {
		for(int i = 0; i < KIND; ++i)
			nxt[L][i] = -1;
		fail[L] = -1;
		end[L] = 0;
		return L++;
	}
	void insert(char *s) {
		int p = root;
		for(int i = 0; s[i]; ++i) {
			int t = mp(s[i]);
			if(nxt[p][t] == -1)
				nxt[p][t] = newnode();
			p = nxt[p][t];
		}
		end[p] = 1;
	}
	void getfail() {
		queue<int> Q;
		fail[root] = root;
		for(int i = 0; i < KIND; ++i) {
			if(nxt[root][i] == -1)
				nxt[root][i] = root;
			else {
				fail[nxt[root][i]] = root;
				Q.push(nxt[root][i]);
			}
		}
		while(!Q.empty()) {
			int tmp = Q.front();
			Q.pop();
			if(end[fail[tmp]] == 1)
				end[tmp] = 1;
			for(int i = 0; i < KIND; ++i) {
				if(nxt[tmp][i] == -1) {
					nxt[tmp][i] = nxt[fail[tmp]][i];
				}
				else {
					fail[nxt[tmp][i]] = nxt[fail[tmp]][i];
					Q.push(nxt[tmp][i]);
				}
			}
		}
	}
	Mat getmatrix() {
		Mat res(L);
		for(int i = 0; i < L; ++i) {
			if(end[i] == 0) {
				for(int j = 0; j < KIND; ++j) {
					if(end[nxt[i][j]] == 0)
						res.mat[i][nxt[i][j]]++;
				}
			}
		}
		return res;
	}
}AC;


int main() {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		AC.init();
		while(n--) {
			scanf("%s", s);
			AC.insert(s);
		}
		AC.getfail();
		Mat tmp = AC.getmatrix();
		printf("%lld\n", Mat_qp(tmp, m));
	}
	return 0;
}
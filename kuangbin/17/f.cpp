#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef unsigned long long ULL;

const int MAXN = 40;
const int KIND = 26;

char s[100];

struct Mat {
	int n;
	ULL a[MAXN][MAXN];
	Mat(int nnn, bool specific = false) {
		n = nnn;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				a[i][j] = 0;
		if(specific) {
			for(int i = 0; i < n; ++i)
				a[i][i] = 1;
		}
	}
	Mat operator*(Mat &rhs) {
		Mat res(rhs.n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int k = 0; k < n; ++k) {
					res.a[i][j] += a[i][k] * rhs.a[k][j];
				}
			}
		}
		return res;
	}
};

Mat Mat_qp(Mat a, int n) {
	Mat res(a.n, 1);
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

ULL qp(ULL a, int n) {
	ULL ans = 1;
	while(n) {
		if(n & 1)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}

struct AC_automation {
	int root, L;
	int nxt[MAXN][KIND], fail[MAXN], forbid[MAXN];
	AC_automation() : L(0) {}
	void init() {
		L = 0;
		root = newnode();
	}
	int newnode() {
		for(int i = 0; i < KIND; ++i)
			nxt[L][i] = -1;
		fail[L] = -1;
		forbid[L] = 0;
		return L++;
	}
	void insert(char *s) {
		int p = root;
		for(int i = 0; s[i]; ++i) {
			int t = s[i] - 'a';
			if(nxt[p][t] == -1)
				nxt[p][t] = newnode();
			p = nxt[p][t];
		}
		forbid[p] = 1;
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
			if(forbid[fail[tmp]] == 1)
				forbid[tmp] = 1;
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
		Mat res(L + 1);
		for(int i = 0; i < L; ++i) {
			if(forbid[i] == 0) {
				for(int j = 0; j < KIND; ++j) {
					if(forbid[nxt[i][j]] == 0)
						res.a[i][nxt[i][j]]++;
				}
			}
		}
		for(int i = 0; i < L + 1; i++)
			res.a[i][L] = 1;
		return res;
	}
}AC;

int main() {
	int n, L;
	while(~scanf("%d %d", &n, &L)) {
		AC.init();
		while(n--) {
			scanf("%s", s);
			AC.insert(s);
		}
		AC.getfail();
		Mat a = AC.getmatrix();
		a = Mat_qp(a, L);
		ULL res = 0;
		for(int i = 0; i < a.n; i++)
			res += a.a[0][i];
		Mat tmp(2);
		tmp.a[0][0] = 26;
		tmp.a[0][1] = tmp.a[1][1] = 1;
		tmp = Mat_qp(tmp, L);
		ULL ans = tmp.a[0][1] + tmp.a[0][0];
		ans -= res;
		printf("%llu\n", ans);
	}
	return 0;
}
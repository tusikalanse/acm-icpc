#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct num {
	LL l, r;
};

LL ans, base;
vector<num> x, y, A[10], B[10];
int T, n, p, q, w[50];

void dfs(int now, int step, LL tmp, vector<num> &x) {
	if(now == step) {
		x.push_back({tmp, 0});
		return;
	}
	dfs(now + 1, step, tmp, x);
	dfs(now + 1, step, tmp + w[now], x);
}

LL get0(vector<num> &A, vector<num> &B, LL limit) {
	LL res = 0;
	int j = B.size() - 1;
	for(int i = 0; i < A.size(); ++i) {
		while(j >= 0 && A[i].r + B[j].r >= limit) j--;
		res += j + 1;
	}
	return res;
}

LL get1(vector<num> &A, vector<num> &B, LL limit) {
	LL res = 0;
	int j = 0;
	for(int i = (int)A.size() - 1; ~i; --i) {
		while(j < B.size() && A[i].r + B[j].r < limit) j++;
		res += (int)B.size() - j;
	}
	return res;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        ans = 0; base = 1;
        x.clear(); y.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) 
            scanf("%d", &w[i]);
       	p = n / 2;
       	dfs(0, p, 0, x);
       	dfs(p, n, 0, y);
       	for(int bit = 1; bit <= 9; ++bit) {
       		for(int i = 0; i <= 9; ++i)
        		A[i].clear(), B[i].clear();
        	for(auto f: x) 
        		A[f.l % 10].push_back({f.l / 10, f.r});
        	for(auto f: y)
        		B[f.l % 10].push_back({f.l / 10, f.r});
        	for(int i = 0; i <= 9; ++i) {
        		int j1 = (14 - i) % 10, j2 = (13 - i) % 10;
        		ans += get0(A[i], B[j1], base) + get1(A[i], B[j2], base);
        	}
        	int nowx = 0, nowy = 0;
        	for(int i = 0; i <= 9; ++i) {
        		for(auto f: A[i])
        			x[nowx++] = (num){f.l, f.r + i * base};
        		for(auto f: B[i])
        			y[nowy++] = (num){f.l, f.r + i * base};
        	}
        	base *= 10;
       	}
        printf("%lld\n", ans);
    }
    return 0;
}

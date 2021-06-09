#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 2e5 + 10;
vector< pair<int, int> > cnt[100];
int T, n, m, l, flag;
char A[N], B[N], C[N << 1];

void init() {
	for(int i = 0; i <= 9; ++i) 
		for(int j = 0; j <= 9; ++j)
			cnt[i * j].push_back(make_pair(i, j));
}

void dfs(int i, int j, int s) {
	if(i == n && j == m && s == l) {
		A[n] = B[m] = '\0';
		if(flag)
			printf("%s %s\n", A, B);
		flag = 0;
		return;
	}
	if(s >= l)
		return;
	if(i + j == 0) {
		int a = C[s] - '0';
		for(auto &it: cnt[a]) {
			A[i] = it.first + '0';
			B[j] = it.second + '0';
			dfs(i + 1, j + 1, s + 1);
		}
		s++;
		if(s < l && a) {
			a = a * 10 + C[s] - '0';
			for(auto &it: cnt[a]) {
				A[i] = it.first + '0';
				B[j] = it.second + '0';
				dfs(i + 1, j + 1, s + 1);
			}		 
		}
	}
	else if(i == 1 && j < m) {
		int a;
		if(s < l) {
			a = C[s] - '0';
			for(auto &it: cnt[a]) {
				if(it.first == A[i - 1] - '0') {
					B[j] = it.second + '0';
					dfs(i, j + 1, s + 1);
				}
			}
		}
		s++;
		if(s < l && a) {
			a = a * 10 + C[s] - '0';
			for(auto &it: cnt[a]) {
				if(it.first == A[i - 1] - '0') {
					B[j] = it.second + '0';
					dfs(i, j + 1, s + 1);
				}
			}
		}
	}
	else if(j == m) {
		int a;
		if(s < l) {
			a = C[s] - '0';
			for(auto &it: cnt[a]) {
				if(it.second == B[j % m] - '0') {
					A[i] = it.first + '0';
					dfs(i + 1, 1, s + 1);
				}
			}
		}
		s++;
		if(s < l && a) {
			a = a * 10 + C[s] - '0';
			for(auto &it: cnt[a]) {
				if(it.second == B[j % m] - '0') {
					A[i] = it.first + '0';
					dfs(i + 1, 1, s + 1);
				}
			}
		}
	}
	else {
		int a;
		if(s < l) {
			a = C[s] - '0';
			for(auto &it: cnt[a]) {
				if(it.first == A[i - 1] - '0' && it.second == B[j] - '0') {
					dfs(i, j + 1, s + 1);
				}
			}
		}
		s++;
		if(s < l && a) {
			a = a * 10 + C[s] - '0';
			for(auto &it: cnt[a]) {
				if(it.first == A[i - 1] - '0' && it.second == B[j] - '0') {
					dfs(i, j + 1, s + 1);
				}
			}
		}
	}
}

int main() {
	init();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%s", &n, &m, C);
		l = strlen(C);
		if(l == 1 && C[0] == '0' && (n == 1 || m == 1)) {
			if(n * m == 1) 
				puts("0 0");
			else if(n == 1) {
				printf("0 1");
				for(int i = 1; i < m; ++i)
					putchar('0');
				puts("");
			}
			else {
				printf("1");
				for(int i = 1; i < n; ++i)
					putchar('0');
				printf(" 0\n");
			}
			continue;
		}
		if(n * m > l || 2 * n * m < l) {
			puts("Impossible");
			continue;
		}
		A[n] = B[m] = '\0';
		flag = 1;
		dfs(0, 0, 0);
		if(flag)
			puts("Impossible");
	}
	return 0;
}
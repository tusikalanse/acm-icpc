#include <bits/stdc++.h>
using namespace std;

const int N = 5300;

int mat[N][N], sum[N][N], n;
stack<int> stk;

char s[N];

int mp(char s) {
	if(s <= '9' && s >= '0')
		return s - '0';
	return s - 'A' + 10;
}

bool check(int x) {
	for(int i = x; i <= n; i += x) {
		for(int j = x; j <= n; j += x) {
			int tmp = sum[i][j] - sum[i - x][j] - sum[i][j - x] + sum[i - x][j - x];
			if(tmp != 0 && tmp != x * x)
				return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for(int j = 1; 4 * j <= n; ++j) {
			int tmp = mp(s[j]);
			mat[i][4 * j] = tmp & 1;
			tmp >>= 1;
			mat[i][4 * j - 1] = tmp & 1;
			tmp >>= 1;
			mat[i][4 * j - 2] = tmp & 1;
			tmp >>= 1;
			mat[i][4 * j - 3] = tmp;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + mat[i][j] - sum[i - 1][j - 1];
		}
	}
	for(int i = 2; i <= n; ++i) {
		if(n % i == 0)
			stk.push(i);
	}
	while(!stk.empty()) {
		int tmp = stk.top();
		stk.pop();
		if(check(tmp)) {
			printf("%d\n", tmp);
			return 0;
		}
	}
	printf("1\n");
	return 0;
}
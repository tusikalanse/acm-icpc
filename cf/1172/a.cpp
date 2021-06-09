#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int a[N], n, ans, flag;

int check() {
	int p;
	for(int i = n; i; --i) {
		if(a[n] - a[i] != n - i)
			return -1;
		if(a[i] == 1) {
			p = i;
			break;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(a[i] == 0) continue;
		if(a[i] == 1)
			break;
		if(a[i] <= n - p + 1 + i)
			return -1;
	}
	return p - 1;
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] != 0)
			flag = 1;
	}
	if(flag == 0) {
		printf("%d\n", n);
		return 0;
	}
	ans = check();
	if(ans == -1) {
		for(int i = 1; i <= n; ++i) {
			if(a[i] == 0) continue;
			ans = max(ans, i + n - a[i] + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, a[100010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		printf("%d ", n + 1 - a[i]);
	}
	puts("");
	return 0;
}
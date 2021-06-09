#include <bits/stdc++.h>
using namespace std;

int a[110], n, vis[110], s, ss, cnt;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	ss = a[1];
	vis[1] = 1;
	cnt = 1;
	for(int i = 2; i <= n; ++i) {
		if(a[1] >= 2 * a[i]) {
			vis[i] = 1;
			ss += a[i];
			cnt++;
		}
	}
	if(2 * ss > s) {
		printf("%d\n", cnt);
		for(int i = 1; i <= n; ++i) {
			if(vis[i])
				printf("%d ", i);
		}
	}
	else {
		puts("0")
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], n;

int binary_search(int val) {
	int ans = n, l = 1, r = n;
	while(l <= r) {
		int mid = l + r >> 1;
		if(b[mid] > val) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}

int main() {
	memset(b, 0x3f, sizeof(b));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	b[1] = a[1];
	for(int i = 2; i <= n; ++i) {
		int pos = binary_search(a[i]);
		b[pos] = a[i];
	}
	for(int i = n; i; --i) {
		if(b[i] != 0x3f3f3f3f) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
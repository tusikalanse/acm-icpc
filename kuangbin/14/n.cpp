#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int check(int n) {
	int ans = 0;
	while(n) {
		n /= 5;
		ans += n;
	}
	return ans;
}

int main() {
	int T, q, cas = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &q);
		int l = 1, r = 0x3fffffff, mid;
		while(l <= r) {
			mid = l + r >> 1;
			if(check(mid) == q)
				break;
			else if(check(mid) < q)
				l = mid + 1;
			else 
				r = mid - 1;
		}
		if(check(mid) != q) {
			printf("Case %d: impossible\n", ++cas);
			continue;
		}
		while(check(mid) == q)
			mid--;
		printf("Case %d: %d\n", ++cas, mid + 1);
	}
	return 0;
}
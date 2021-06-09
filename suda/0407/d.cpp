#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	while(~scanf("%d %d", &n, &m) && n) {
		long long ans = 1LL*n*m;
		if(m > n)
			swap(m, n);
		for(int i = 3; i <= m; i += 2) {
			ans += 1LL*(n-i+1)*(m-i+1)*i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
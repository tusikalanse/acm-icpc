#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int a[100010], w[100010];
int s[100010];


int main() {
	ll ans = 0;
	int n, p;
	while(~scanf("%d", &n) && n) {
		p = 0;
		ans = 0;
		s[0] = 0;
		for(int i = 1; i <= n; i++) 
			scanf("%d", &a[i]);
		a[n + 1] = 0;
		for(int i = 1; i <= n + 1; i++) {
			if(a[i] > s[p]) {
				s[++p] = a[i];
				w[p] = 1;
			}
			else {
				int wid = 0;
				while(s[p] > a[i]) {
					wid += w[p];
					ans = max(ans, 1LL * wid * s[p]);
					p--;
				}
				s[++p] = a[i];
				w[p] = wid + 1;
			}
		}
		printf("%lld\n", ans);
	}




	return 0;
}
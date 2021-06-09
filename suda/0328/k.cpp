#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1000006];

int main() {
	int T, n, cas = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) 
			scanf("%d", &a[i]);
		int ans = 0, mmin = a[n];
		for(int i = n - 1; i >= 0; i--) {
			if(mmin > a[i])
				mmin = a[i];
			else 
				ans++;
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
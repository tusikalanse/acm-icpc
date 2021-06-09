#include <bits/stdc++.h>
using namespace std;


int a[500010], pos[500010];
long long sum = 0, tmp = 0;
int main() {
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int cnt = 0;
	if(sum % 3)
		return !printf("%d\n", 0);
	for(int i = 1; i <= n; i++) {
		pos[i] = cnt;
		tmp += a[i];
		if(tmp == sum/3)
			cnt++;			
	}
	tmp = 0;
	for(int i = n; i > 0; i--) {
		tmp += a[i];
		if(tmp == sum/3)
			ans += pos[i-1];
	}
	printf("%lld\n", ans);
	return 0;
}
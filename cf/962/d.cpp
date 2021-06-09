#include <bits/stdc++.h>
using namespace std;

long long a[150010];
map<long long, int> locate;

int main() {
	long long n, t;
	scanf("%lld", &n);
	int ans = n;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		t = a[i];
		while(0 != locate[t]) {
			a[i] = 2*t;
			ans--;
			a[locate[t]] = 0;
			locate[t] = 0;
			t = 2*t;
		}
		locate[t] = i;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++) 
		if(a[i])
			printf("%lld%c", a[i], ((i==n) ? '\n' : ' '));
	return 0;
}
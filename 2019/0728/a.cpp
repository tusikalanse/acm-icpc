#include <bits/stdc++.h>
using namespace std;

int T, n, k;

int main() {
	cin >> T;
	while(T--) {
		cin >> k >> n;;
		if(k == 1) {
			cout << n - 1 << endl;
			continue;
		}
		long long sum = 0, now = 1, p = 0;
		while(sum + now < n) {
			sum += now;
			now *= k;
			p++;
		}
		n -= sum;
		if(n <= now / k) {
			printf("%lld\n", p + p - 1);
		}
		else 
			printf("%lld\n", p * 2);
	}
	return 0;
}
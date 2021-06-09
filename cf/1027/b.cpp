#include <bits/stdc++.h>
using namespace std;

long long n, m, x, y;

long long query() {
	if(n % 2 == 0) {
		if((x + y) % 2 == 0) 
			return (x - 1) * n / 2 + (y + 1) / 2;
		else
			return n * n / 2 + (x - 1) * n / 2 + (y + 1) / 2;
	} 
	else {
		if((x + y) % 2 == 0) {
			if(x % 2 == 1) {
				return n * (x / 2) + (y + 1) / 2;
			}
			else
				return n * ((x - 1) / 2) + (n + 1) / 2 + (y + 1) / 2;
		}
		else {
			if(x % 2 == 1) {
				return n * n / 2 + 1 + n * (x / 2) + (y + 1) / 2;
			}
			else
				return n * n / 2 + 1 + n * ((x - 1) / 2) + n / 2 + (y + 1) / 2;
		}
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	while(m--) {
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", query());
	}



	return 0;
}
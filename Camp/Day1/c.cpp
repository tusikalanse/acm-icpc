#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

int T;
LL a, b, a1, b1, a2, b2;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &a, &b);
		if(gcd(a, b) == 1) {
			printf("1\n%lld %lld\n", a, b);
			continue;
		}
		bool flag = 0;
		puts("2");
		if((a - b) % 2 == 0) {
			if(a > b)
				swap(a, b), flag ^= 1;
			a1 = 2, a2 = a - 2;
			b1 = b - a + 3, b2 = a - 3;
			if(flag)
				swap(a1, b1), swap(a2, b2);
			printf("%lld %lld\n%lld %lld\n", a1, b1, a2, b2);
		}
		else {
			if((a & 1) == 0)
				swap(a, b), flag ^= 1;
			if(a == 5) {
				a1 = 2, a2 = 3;
				b1 = b - 5, b2 = 5;
				if(flag)
				swap(a1, b1), swap(a2, b2);
				printf("%lld %lld\n%lld %lld\n", a1, b1, a2, b2);
				continue;
			}
			a1 = 2, a2 = a - 2;
			b1 = b - 3, b2 = 3;
			if(a2 % b2 == 0)
				a1 = 4, a2 = a - 4;
			if(flag)
				swap(a1, b1), swap(a2, b2);
			printf("%lld %lld\n%lld %lld\n", a1, b1, a2, b2);
		}
	}
	return 0;
}
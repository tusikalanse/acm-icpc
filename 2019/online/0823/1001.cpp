#include <bits/stdc++.h>
using namespace std;

int T;
long long A, B, C;


int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &A, &B);
		C = 0;
		for(int i = 31; ~i; --i) {
			if(((A >> i) & 1) && ((B >> i) & 1))
				C += 1LL << i;
		}
		if(C)
			printf("%lld\n", C);
		else {
			for(int i = 0; i < 32; ++i) {
				if(((A >> i) & 1) || ((B >> i) & 1)) {
					C += 1LL << i;
					break;
				}
			}
			printf("%lld\n", C);
		}
	}
	return 0;
}
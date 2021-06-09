#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define LL long long

int main() {
	int t;
	LL n, k;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; ++cas) {
		bool flag = false;
		printf("Case #%d:\n", cas);
		scanf("%lld%lld", &n, &k);
		if((n & 1) == 0) {
			n--;
			flag = true;
		}
		LL res = (((1LL << (k + 1)) - 1) - n) >> 1;
		for(int i = 0; i < k - 1; ++i) {
			LL tmp = 1LL << i;
			if(res & 1)
				printf("%lld -\n", tmp);
			else
				printf("%lld +\n", tmp);
			res >>= 1;
		}
		LL tmp = 1LL << (k - 1);
		if(flag) 
			printf("%lld +\n", tmp + 1);
		else
			printf("%lld +\n", tmp);
	}
	return 0;
}
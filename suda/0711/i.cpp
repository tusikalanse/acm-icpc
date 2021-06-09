#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 4000010;

int euler[MAXN];
long long ans[MAXN];

void init() {
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i < MAXN; ++i)
		euler[i] = i;
	for(int i = 2; i < MAXN; ++i) {
		if(euler[i] == i) {
			for(int j = i; j < MAXN; j += i)
				euler[j] = euler[j] / i * (i - 1);
		}
		for(int j = 1; 1LL * j * i < MAXN; ++j) {
			ans[j * i] += j * euler[i];
		}
	}
	for(int i = 2; i < MAXN; ++i)
		ans[i] += ans[i - 1];
}

int main() {
	init();
	int n;
	while(~scanf("%d", &n) && n) 
		printf("%lld\n", ans[n]);
	return 0;
}
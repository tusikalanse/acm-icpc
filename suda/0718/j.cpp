#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int prime[10010], cnt = 0, ans[10010], sum[10010];
bool isp[10010];

void init() {
	memset(isp, 1, sizeof(isp));
	isp[1] = 0;
	for(int i = 2; i <= 10000; ++i) {
		if(isp[i]) prime[++cnt] = i;
		for(int j = 2; j * i <= 10000; ++j)
			isp[i * j] = 0;
	}
	sum[0] = 0;
	for(int i = 1; i <= cnt; ++i) {
		sum[i] = sum[i - 1] + prime[i];
	}
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= cnt; ++i)
		for(int j = i; j <= cnt; ++j)
			if(sum[j] - sum[i - 1] <= 10000)
				ans[sum[j] - sum[i - 1]]++;
}


int main() {
	init();
	int n;
	while(~scanf("%d", &n) && n)
		printf("%d\n", ans[n]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

int cnt[N + 8], np[N], n, m, l, r;
long long sum[N + 8];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &m);
		cnt[m]++;
	}
	for(int i = 2; i < N; ++i) {
		if(np[i] == 0) {
			for(int j = i; j < N; j += i)
				np[j] = 1;
			for(int j = i; j <= N; j += i)
				sum[i] += cnt[j];
		}
	}
	for(int i = 1; i <= N; ++i)
		sum[i] += sum[i - 1];
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &l, &r);
		if(l >= 1e7 && r >= 1e7) {
			printf("0\n");
			continue;
		}
		if(r >= 1e7) {
			printf("%lld\n", sum[N] - sum[l - 1]);
		}
		else
			printf("%lld\n", sum[r] - sum[l - 1]);
	}
	return 0;
}
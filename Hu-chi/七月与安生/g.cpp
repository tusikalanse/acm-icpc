#include <bits/stdc++.h>
#define LL long long
using namespace std;

int a[2100];
int dif[5100];
pair<int, int> ds[13000000];
LL sum[13000000];


int main() {
	int n;
	memset(dif, 0, sizeof(dif));
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < i; ++j)
			dif[a[i] - a[j]]++;
	int t = 0;
	for(int i = 0; i < 5000; ++i)
		if(dif[i])
			for(int j = 0; i + j < 5000; ++j)
				if(dif[j])
					ds[t++] = make_pair(i + j, dif[i] * dif[j]);
	sort(ds, ds + t);
	sum[0] = ds[0].second;
	for(int i = 1; i < t; ++i)
		sum[i] = sum[i - 1] + ds[i].second;
	double ans = 0;
	double div = n * (n - 1) / 2;
	div = div * div * div;
	for(int i = 0; i < 5000; ++i) {
		if(dif[i]) {
			int id = lower_bound(ds, ds + t, make_pair(i, 0)) - ds;
			if(id > 0)
				ans += 1.0 * dif[i] * sum[id - 1];
		}
	}
	ans /= div;
	printf("%.10f\n", ans);
	return 0;
}
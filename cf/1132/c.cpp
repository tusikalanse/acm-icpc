#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int f[N], uni[N], l[N], r[N], n, q, ans, tmp;

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= q; ++i) {
		scanf("%d%d", &l[i], &r[i]);
	}
	for(int ig = 1; ig <= q; ++ig) {
		memset(f, 0, sizeof(f));
		memset(uni, 0, sizeof(uni));
		for(int i = 1; i <= q; ++i) {
			if(i != ig) {
				f[l[i]]++;
				f[r[i] + 1]--;
			}
		}
		int tot = 0, sum = 0;
		for(int i = 1; i <= n; ++i) {
			sum += f[i];
			tot += sum != 0;
			uni[i] = uni[i - 1];
			if(sum == 1) {
				uni[i]++;
			}
		}
		for(int i = 1; i <= q; ++i) {
			if(i != ig) {
				tmp = tot - (uni[r[i]] - uni[l[i] - 1]);
				ans = max(ans, tmp);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
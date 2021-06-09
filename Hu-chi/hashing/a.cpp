#include <bits/stdc++.h>
#define LL long long
#define mp make_pair

using namespace std;

LL sum[2010][2010];
pair<int, int> odd, even;
LL omax = -1, emax = -1;
int a[2010][2010], n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			sum[i][j] -= a[i][j];
		}
	}
	for(int ij = 2; ij <= 2 * n; ++ij) {
		LL tot = 0;
		for(int i = 1; i <= n; ++i) {
			int j = ij - i;
			if(j >= 1 && j <= n)
				tot += a[i][j];
		}
		for(int i = 1; i <= n; ++i) {
			int j = ij - i;
			if(j >= 1 && j <= n)
				sum[i][j] += tot;
		}
	}
	for(int ij = 1 - n; ij <= n - 1; ++ij) {
		LL tot = 0;
		for(int i = 1; i <= n; ++i) {
			int j = i + ij;
			if(j >= 1 && j <= n)
				tot += a[i][j];
		}
		for(int i = 1; i <= n; ++i) {
			int j = i + ij;
			if(j >= 1 && j <= n)
				sum[i][j] += tot;
		}
	}
	for(int ij = 2; ij <= 2 * n; ij += 2) {
		for(int i = 1; i <= n; ++i) {
			int j = ij - i;
			if(j >= 1 && j <= n) {
				if(sum[i][j] > emax) {
					emax = sum[i][j];
					even = mp(i, j);
				}
			}
		}
	}
	for(int ij = 3; ij <= 2 * n; ij += 2) {
		for(int i = 1; i <= n; ++i) {
			int j = ij - i;
			if(j >= 1 && j <= n) {
				if(sum[i][j] > omax) {
					omax = sum[i][j];
					odd = mp(i, j);
				}
			}
		}
	}
	printf("%lld \n%d %d %d %d\n", omax + emax, odd.first, odd.second, even.first, even.second);
	return 0;
}
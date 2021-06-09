#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int r[N];

int main() {
	for (int i = 1; i < N; ++i) {
		int x = i;
		int flag = 1, j = 2;
		while (j * j <= x) {
			if (x % j == 0) {
				if (x % (j * j) == 0) {
					flag = 0;
					break;
				}
				x /= j;
			}
			j++;
		}
		if (flag)
			r[i] = i;
	}
	double mn = 1e9;
	for (int i = 1; i < N; ++i) {
		double ans = 0;
		for (int j = 1; j <= i; ++j) {
			if (i % j == 0 && r[j])
				ans += 1.0 / r[j];
		}
		ans = 1.0 / ans;
		if (ans < mn) {
			cout << i << " " << ans << endl;
			mn = ans;
		}
	}
	return 0;
}
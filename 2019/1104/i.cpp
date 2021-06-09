#include <bits/stdc++.h>
using namespace std;

int a[10], n;

int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		int b[11];
		for (int i = 1; i <= n; ++i) b[i] = i;
		int cnt = 0;
		do {
			int mx = -1e9, mn = 1e9;
			int flag = 1;
			for (int i = 1; i <= n; ++i) {
				mx = max(mx, b[i]);
				mn = min(mn, b[i]);
				if (mx - mn != a[i])
					flag = 0;
			}
			cnt += flag;
		} while (next_permutation(b + 1, b + n + 1));
		cout << cnt << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int T, n, a[N], ans;

unordered_map<int, int> cnt;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = 0; cnt.clear();
		for (int i = 1; i <= n; ++i) {scanf("%d", &a[i]); cnt[a[i]]++;}
		for (int mid = 1; mid <= n; ++mid) {
			cnt[a[mid]]--;
			for (int left = 1; left < mid; ++left) 
				if (cnt.count(2 * a[mid] - a[left])) ans += cnt[2 * a[mid] - a[left]];
		}
		printf("%d\n", ans);
	}
	return 0;
}
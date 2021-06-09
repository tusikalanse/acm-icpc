#include <bits/stdc++.h>
using namespace std;

vector<int> l, r;
int a[40];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	l.push_back(0);
	r.push_back(0);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] %= m;
	}
	for(int i = 1; i <= n/2; ++i) {
		int num = l.size();
		for(int j = 0; j < num; ++j)
			l.push_back((l[j] + a[i]) % m);
	}
	sort(l.begin(), l.end());
	l.erase(unique(l.begin(), l.end()), l.end());
	for(int i = 1 + n/2; i <= n; ++i) {
		int num = r.size();
		for(int j = 0; j < num; ++j)
			r.push_back((r[j] + a[i]) % m);
	}
	sort(r.begin(), r.end());
	r.erase(unique(r.begin(), r.end()), r.end());
	int ans = 0, tmp = 0;
	for(int i = 0; i < l.size(); ++i) {
		int L = l[i], R = m - 1, mid;
		while(L <= R) {
			mid = L + R >> 1;
			if(lower_bound(r.begin(), r.end(), (mid + m - l[i]) % m) != r.end() && l[i] + *(lower_bound(r.begin(), r.end(), (mid + m - l[i]) % m)) < m) {
				tmp = mid;
				L = mid + 1;
			}
			else
				R = mid - 1;
		}
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
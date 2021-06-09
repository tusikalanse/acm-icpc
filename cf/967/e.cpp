#include <bits/stdc++.h>
using namespace std;


long long a[100010], s[100010];
long long n, A, B;

bool check(int num, int pos, vector<long long> &lst) {
	long long aaa = s[n] - s[pos-1];
	for(int i = 0; i < num; ++i) {
		aaa -= *(lst.rbegin() + i);
	}
	return a[pos] * A >= B * aaa;
}


int main() {
	scanf("%lld %lld %lld", &n, &A, &B);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		s[i] = a[i] + s[i-1];
	}
	int ans = n - 1;
	vector<long long> lst(&a[1], &a[n+1]);
	sort(lst.begin(), lst.end());
	for(int i = 1; i < n ; ++i) {
		int l = 0, r = n - i, temp = n - i;
		lst.erase(find(lst.begin(), lst.end(), a[i]));
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid, i, lst)) {
				temp = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		ans = min(ans, temp + i - 1);	//	printf("%d %d %d\n", i, temp, ans);
	}
	printf("%d\n", ans);
	return 0;
}
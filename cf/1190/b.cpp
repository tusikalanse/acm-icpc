#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], mx, df, p;
map<int, int> cnt;
long long tot;

void csl() {
	cout << "cslnb" << endl;
	exit(0);
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		mx = max(mx, cnt[a[i]]);
		if(cnt[a[i]] == 2) {
			p = a[i];
			df++;
		}
	}
	if(n == 1 && a[1] == 0) {
		csl();
	}
	if(mx > 2)
		csl();
	if(df > 1)
		csl();
	if(df == 1 && cnt[p - 1] != 0)
		csl();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		if(a[i] <= i - 2)
			csl();
		tot += a[i] - (i - 1);
	}
	if(tot % 2 == 0)
		csl();
	cout << "sjfnb" << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int a[1010] = {0};


int main() {
	int n, m, t;
	cin >> n >> m;
	while(m--) {
		cin >> t;
		a[t]++;
	}
	int mmin = 100000;
	for(int i = 1; i <= n; i++)
		mmin = min(mmin, a[i]);
	printf("%d\n", mmin);
	return 0;
}
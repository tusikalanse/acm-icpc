#include <bits/stdc++.h>
using namespace std;

int a[100010], t[100010];


int main() {
	int mmax = 0, ans = 0, temp = 0;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}
	for(int i = 1; i <= k; i++) {
		if(t[i])
			ans += a[i];
		else
			temp += a[i];
	}
	mmax = temp;
	for(int i = k + 1; i <= n; i++) {
		if(t[i])
			ans += a[i];
		else
			temp += a[i];
		if(t[i-k] == 0)
			temp -= a[i-k];
		mmax = max(mmax, temp);
	}
	printf("%d\n", mmax + ans);
 


	return 0;
}
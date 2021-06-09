#include <bits/stdc++.h>
#define LL long long 
using namespace std;

double comp(int n, int m) {
	double ans = 1;
	for(int i = 0; i < m; ++i)
		ans = ans * (n - i) / (i + 1);
	return ans;
}

double qp(double a, int n) {
	double ans = 1;
	while(n) {
		if(n & 1)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}

int a[3010], n;

int main() {
	cin >> n;
	int ni = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(a[j] < a[i])
				ni++;
	double ans = 0;
	for(int i = ni; i <= 300; i += 2) {
		printf("%d %d %f\n", i, i / 2, comp(i, i / 2));
		ans += i / qp(2, i / 2) * comp(i, i / 2);
	}
	printf("%.15f\n", ans);
	return 0;
}
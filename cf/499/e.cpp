#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, k, a;

int main() {
	scanf("%d%d",&n,&k);
	int g = k;
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		a = a % k;
		g = __gcd(g, a);
	}
	cout << k / g << endl;
	for(int i = 0; i < k; i += g)
		cout << i << ' ';
	return 0;
} 
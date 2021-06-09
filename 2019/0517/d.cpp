#include <bits/stdc++.h>
using namespace std;

int T, k, a[100010], n, m;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &k);
		for(int i = 0; i < k; ++i) 
			scanf("%1d", &a[i]);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; ++i)
			scanf("%*d%*d");
		printf("%d\n", a[(((m - n + 1) % k) + k) % k] == 1 ? 2 : 1);
	}


	return 0;
}
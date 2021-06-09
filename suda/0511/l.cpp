#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct node {
	string t;
	int n;
	bool operator< (const node &rhs) const {
		if(n == rhs.n) 
			return t < rhs.t;
		else 
			return n > rhs.n;
	}
}a[110];

int main() {
	int T, n, m;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		long long ans = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].t >> a[i].n;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= m; ++i) {
			ans += 1LL * (m - i + 1) * a[i].n;
		}
		printf("%lld", ans);
		for(int i = 1; i <= m; ++i)
			cout << " " << a[i].t;
		cout << endl;
	}

	return 0;
}
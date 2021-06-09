#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, p[N], cas;
long long ans, tot;

void init() {
	int i = 1;
	while(true) {
		int d = 1LL * i * (i - 1) / 2, dd = 1LL * (i + 1) * (i) / 2;
		if(d > N)
			break;
		for(int j = d + 1; j <= dd && j < N; ++j)
			p[j] = i;
		i++;
	}
}

struct node {
	int h, a;
	bool operator<(const node &rhs) const {
		return 1LL * rhs.a * h < 1LL * rhs.h * a; 
	}
}mon[N];

int main() {
	init();
	scanf("%d", &T);
	while(T--) {
		ans = tot = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &mon[i].h, &mon[i].a);
			mon[i].h = p[mon[i].h];
			tot += mon[i].a;
		}
		sort(mon + 1, mon + n + 1);
		for(int i = 1; i <= n; ++i) {
			// cout << mon[i].a << " " << mon[i].h << endl;
			ans += 1LL * tot * mon[i].h;
			tot -= mon[i].a;
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}
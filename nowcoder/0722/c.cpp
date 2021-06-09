#include <bits/stdc++.h>
#define min(a,b) (a > b ? b : a)
using namespace std;
using LL = long long;



int queen[] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712};
LL fib[100], x, m;

LL solve(LL x, int m, int n) {
	LL ans = 0;
	while(x) {
		ans += x / m;
		x /= m;
	}
	return ans / n;
}

int main() {
	bool flag = 0;
	fib[0] = fib[1] = 1;
	for(int i = 2; i <= 11111111; ++i) {
		if(fib[i - 1] + fib[i - 2] > 1e18) 
			break;
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	cin >> x >> m;
	for(int i = 0; i < 90; ++i) {
		if(fib[i] == x) {
			flag = 1;
			break;
		}
	}
	if(flag == 0) {
		printf("%d\n", queen[x % min(13, m)]);
	}
	else {
		vector< pair<int, int> > div;
		for(int i = 2; i * i <= m; ++i) {
			if(m % i == 0)
				div.push_back(make_pair(i, 0));
			while(m % i == 0) {
				div[div.size() - 1].second++;
				m /= i;
			}
		}
		if(m != 1)
			div.push_back(make_pair(m, 1));
		LL ans = 1e18;
		for(int i = 0; i < div.size(); ++i) {
			ans = min(ans, solve(x, div[i].first, div[i].second));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
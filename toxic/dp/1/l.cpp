#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct hanoi {
	int a, b;
	long long h;
	bool operator<(const hanoi &rhs) const {
		if(b == rhs.b) 
			return a > rhs.a;
		return b > rhs.b;
	}
}a[N];

stack<hanoi> stk;

int n;

int main() {
	long long ans = 0, tmp = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%lld", &a[i].a, &a[i].b, &a[i].h);
	}
	sort(a + 1, a + n + 1);
	stk.push({0, 0, 0});
	for(int i = 1; i <= n; ++i) {
		while(stk.top().a >= a[i].b)
			stk.pop();
		tmp = a[i].h + stk.top().h;
		stk.push({a[i].a, a[i].b, tmp});
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}
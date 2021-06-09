#include <bits/stdc++.h>
using namespace std;

int n, a, x, y;
set<int> s;
map<int, int> dep;

int main() {
	s.insert(0);
	s.insert(1000000001);
	scanf("%d%d", &n, &a);
	s.insert(a);
	dep[0] = dep[1000000001] = 0;
	dep[a] = 1;
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &a);
		x = *--s.lower_bound(a);
		y = *s.lower_bound(a);
		printf("%d%c", dep[x] > dep[y] ? x : y, " \n"[i == n]);
		dep[a] = max(dep[x], dep[y]) + 1;
		s.insert(a);
	}
	return 0;
}
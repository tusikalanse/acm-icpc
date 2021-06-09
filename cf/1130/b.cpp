#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int pos[N][2], n, c;
long long ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; ++i) {
		scanf("%d", &c);
		if(pos[c][0] == 0)
			pos[c][0] = i;
		else
			pos[c][1] = i;
	}
	ans = pos[1][0] + pos[1][1] - 2;
	for(int i = 2; i <= n; ++i) 
		ans += min(abs(pos[i][0] - pos[i - 1][0]) + abs(pos[i][1] - pos[i - 1][1]), abs(pos[i][0] - pos[i - 1][1]) + abs(pos[i][1] - pos[i - 1][0]));
	printf("%lld\n", ans);
	return 0;
}
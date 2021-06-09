#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], n, c[2], ans, tmp;
char s[N];
vector<int> pos[N << 1];


int main() {
	tmp = N;
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '0') {
			tmp--;
			c[0]++;
		}
		else {
			tmp++;
			c[1]++;
		}
		pos[tmp].push_back(i);
	}
	tmp = N;
	if(!pos[tmp].empty())
		ans = pos[tmp].back();
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '0') {
			tmp--;
		}
		else {
			tmp++;
		}
		ans = max(ans, pos[tmp].back() - i);
	}
	printf("%d %d\n", ans, 2 * min(c[0], c[1]));
	return 0;
}
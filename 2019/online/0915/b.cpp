#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

short int b[N];

int T, n, m, l[1010], r[1010], cas;
vector<int> num;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		num.clear();
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d", &l[i], &r[i]);
			b[l[i]]++; b[r[i] + 1]--;
			num.push_back(l[i]);
			num.push_back(r[i] + 1);
		}
		sort(num.begin(), num.end());
		num.erase(unique(num.begin(), num.end()), num.end());
		num.push_back(n + 1);
		int tmp = 0, ans = 0;
		for(int i = 0; i + 1 < num.size(); ++i) {
			tmp += b[num[i]];
			ans += (tmp % 2 == 1) * (num[i + 1] - num[i]);
		}
		for(int i = 1; i <= m; ++i) {
			b[l[i]]--; b[r[i] + 1]++;
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
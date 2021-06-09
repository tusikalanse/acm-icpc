#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, n, m;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas)
	{
		cin >> n >> m;
		double ans = 0.5 + 0.5 * (n == 1);
		printf("Case #%d: %.6f %.6f\n", cas, ans, (m + 1.0) / 2 / m);
	}
}
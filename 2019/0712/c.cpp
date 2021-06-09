#include<bits/stdc++.h>
using namespace std;

int T, n, m;

char a[58], b[58], c[58];

int main()
{
	cin >> T;
	for (int cas = 1; cas <= T; ++cas)
	{
		cin >> n >> m;
		cin >> a + 1 >> b + 1 >> c + 1;
		int x = (b[1] - a[1] + 26) % 26;
		for (int i = 1; i <= m; ++i)
		{
			c[i] = c[i] - 'A';
			c[i] = (c[i] - x + 26) % 26;
			c[i] = c[i] + 'A';
		}
		printf("Case #%d: %s\n", cas, c + 1);
	}
}
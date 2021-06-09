#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int n;
LL a[100008];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		LL s = 0, ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", &a[i]);
			s += a[i];
		}
		LL c = s / n;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] > c)
			{
				ans += a[i] - c;
				s -= a[i] - c;	
				a[i] = c;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
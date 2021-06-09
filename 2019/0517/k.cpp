#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL qp(LL a, LL b, LL mod)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	int T;
	LL a, p;
	a = 0;
	while (++a)
	{
		for (LL p = 1; p <= 15; ++p)
		{
			LL ans = 0;
			LL mod = qp(2, p, 2147483647LL);
			for (LL x = 1; x <= mod; ++x)
			{
				if (qp(a, x, mod) == qp(x, a, mod))
					ans++;
			}
			//printf("a = %lld  p = %lld  ans = %lld\n", a, p, ans);
			printf("%lld\t", ans);
		}
		printf("\n");
		if(a > 20)
			break;
	}
	
}
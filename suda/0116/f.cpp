#include <cstdio>
#include <algorithm>
typedef long long LL;

LL p, q, ans;
LL mui(LL m, LL n, LL mod){
	LL res = 0;
	while(n){
		if(n&1)
			res += m;
		m = (m+m)%mod;
		res %= mod;
		n >>= 1;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld", &p, &q);
		if(p&1)
			ans = mui((p-1)/2, p-2, q);
		else 
			ans = mui(p-1, (p-2)/2, q);
		printf("%lld\n", ans);
	}
	return 0;
}
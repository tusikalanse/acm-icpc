#include <bits/stdc++.h>
using namespace std;

long long k, d, t, T, per, ans;

int main(){
	scanf("%lld %lld %lld", &k, &d, &t);
	T = d * (k / d + (k%d > 0));
	t *= 2;
	per = 2 * k + (T-k);
	ans = T * (t/per);
	t %= per;
	if(t >= 2*k){
		t -= 2*k;
		ans += k + t;
		printf("%lld.0\n", ans);
	}
	else {
		ans += t/2;
		printf("%lld", ans);
		if(t&1) puts(".5");
		else puts(".0");
	}
	return 0;
}
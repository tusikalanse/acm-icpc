#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, k, a, b, cost = 0;
	scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
	while(n != 1){
		if(k == 1){
			cost += a*(n-1);
			n = 1;
		}
		else{
			if(n % k == 0){
				if( b <= a*(n - n/k) ){
				cost += b;
				n /= k;
				}
				else{
					cost += a*(n - n/k);
					n /= k;
				}
			}
			else{
				cost += a*(n - max(1LL, k*(n/k)));
				n = max(1LL, k*(n/k));
			}
		}
		//printf("%lld\n", n);
	}
	printf("%lld\n", cost);
	return 0;
}
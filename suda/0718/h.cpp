#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

const LL INF = 0x7fffffffffffffffll;
LL n, ans;
int isc(LL a){
	if(a < 2) return 0;
	LL s = a;
	for(int i = 2; i * i < a; i++){
		if(a % i == 0){
			if(a % (i * i) == 0)
				return 0;
			a = a / i;
		}
	}
	ans = min(ans, abs(s * s - n));
	return 1;
}
int main(){
	int t, flag;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		ans = INF;
		flag = 0;
		LL x = (LL)(sqrt(n) + 0.5);
		for(int i = 0; ; i++){
			if(isc(x - i)) 
				flag = 1;
			if(isc(x + i))
				flag = 1;
			if (flag){
				printf("%lld\n", ans); 
				break;
			}		
		}
	}
	return 0;
}

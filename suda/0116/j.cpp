#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const long long INF = 0x7fffffffffffffffll;
long long n, ans;
int isc(long long a){
	if(a<2) return 0;
	long long s = a;
	for(int i = 2; i*i < a; i++){
		if(a%i == 0){
			if(a%(i*i) == 0)
				return 0;
			a = a/i;
		}
	}
	ans = min(ans, abs(s*s-n));
	return 1;
}
int main(){
	int t, flag;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		ans = INF;
		flag = 0;
		long long x = (long long)(sqrt(n)+0.5);
		for(int i = 0; ; i++){
			if(isc(x-i)) 
				flag = 1;
			if(isc(x+i))
				flag = 1;
			if (flag){
				printf("%lld\n", ans); 
				break;
			}		
		}
	}
	return 0;
}

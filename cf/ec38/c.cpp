#include <bits/stdc++.h>
using namespace std;

//  s = n/(2*m-1) + (n%(2*m-1) > 0)

int main(){
	long long t, n, m, x, flag, s;
	scanf("%lld", &t);
	while(t--){
		flag = 1;
		scanf("%lld", &x);
		if(!x) puts("1 1");
		else{
			for(long long i = (long long)sqrt(x); i<=50000; i++){
				if(i*i == x) continue;
				if(i*i > 2*x) break;
				s = (long long)sqrt(i*i-x);
				if(i*i - s*s == x){
					n = i;
					m = n/(s+1);
					while(m <= n){
						if(n/m != s) m++;
						else {
							flag = 0;
							break;
						}
					}
					if(!flag) break;
				}
			}
			if(flag) puts("-1");
			else printf("%lld %lld\n", n, m);
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m, v, t, num, left = -1;
	scanf("%lld %lld", &n, &m);
	for(long long i = 1; i<=m; i++){
		scanf("%lld", &v);
		if(v >= n){
		if(left == -1){
			t = i;
			num = n/v;
			left = n%v;
		}
		else{
			if(n%v < left){
				t = i;
				num = n/v;
				left = n%v;
			}
		}
		}
	}
	if(left == -1) puts("1 0");
	else printf("%lld %lld\n", t, num);
	return 0;
}
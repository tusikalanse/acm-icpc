#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>


int main(){
	long long a, b;
	int ans = 0;
	scanf("%lld %lld", &a, &b);
	while(a<<ans <= b) ans++;
	printf("%d", ans);
	return 0;
	
}

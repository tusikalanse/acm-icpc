#include <cstdio>
#include <algorithm>

int main(){
	int t, k, n;
	int list[100006];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		for(int i = 0; i<n-1; i++) scanf("%d", &list[i]);
		if (k>=n) {printf("%d\n", n);}
		else{
		std::sort(list, list+n-1);
		long long sum = n;
		for(int i = 0; i<n-k; i++) sum += list[i];
		printf("%lld\n", sum);
		}
	}
	return 0;
}

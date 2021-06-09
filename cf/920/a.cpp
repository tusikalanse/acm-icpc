#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, n, k, ans, t1, t2;
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%d %d", &n, &k);
		for(int i = 1; i<=k; i++){
			scanf("%d", &t1);
			if(i == 1)
				ans = max(ans, t1);
			if(i == k)
				ans = max(ans, n-t1+1);
			if(i>1 && i<=k)
				ans = max(ans, (t1 - t2)/2 + 1);
			t2 = t1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	int a = 1, b = 1e6, ans = 0, n, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		ans = max(ans, min(abs(a-t), abs(b-t)));
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, ans;
	scanf("%lld", &a);
	if(a <= 5){
		if(a == 3)
			ans = 1;
		else if(a == 4)
			ans = 3;
		else 
			ans = 9;
	}
	else
		ans = 1 + (a-3)*3 + (a-3)*(a-4);
	printf("%lld\n", ans);
}
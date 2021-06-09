#include <bits/stdc++.h>
using namespace std;

char s[100000];
int n;
long long ans;

int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i) 
		if(s[i] % 2 == 0)
			ans += i;
	printf("%lld\n", ans);
	return 0;
}
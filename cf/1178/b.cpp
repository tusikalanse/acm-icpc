#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int n;
long long ans, pre, preo;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'v') {
			if(s[i - 1] == 'v') {
				ans += preo;
				pre++;
			}
		}
		if(s[i] == 'o')
			preo += pre;
	}
	printf("%lld\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int s[1000];


int main() {
	int a, n, ans = 0, s1, s2;
	scanf("%d %d", &n, &a);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
	}
	ans += s[a];
	s1 = s2 = ans;
	if(a <= n/2) {
		for(int i = 1; a - i > 0; i++) {
			s1 += s[a-i] + s[a+i];
			if(s1 - s2 == 2)
				ans += 2;
			s2 = s1;
		}
		for(int i = 2 * a; i <= n; i++){
			ans += s[i];
		}
	}
	else {
		for(int i = 1; a + i <= n; i++) {
			s1 += s[a-i] + s[a+i];
			if(s1 - s2 == 2)
				ans += 2;
			s2 = s1;
		}
		for(int i = 2*a - n - 1; i > 0; i--)
			ans += s[i];
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 998244353;

int n;
char s[N];
int cnt[26], num, l, r;
int main() {
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; ++i)
		num += (cnt[i] != 0);
	if(num == 1) {
		printf("%lld\n", (1LL * n * (n + 1)) % mod);
		return 0;
	}
	l = 0, r = n - 1;
	for(; l < n; ++l)
		if(s[0] != s[l])
			break;
	l--;
	for(; r >= 0; --r)
		if(s[n - 1] != s[r])
			break;
	r++;
	if(s[0] == s[n - 1]) {
		printf("%lld\n", (1LL * (l + 2) * (1 + n - r)) % mod);
		return 0;
	}
	else {
		printf("%lld\n", (2LL + l + n - r) % mod);
		return 0;
	}
	return 0;
}
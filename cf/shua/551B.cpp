#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

char s[N], a[N], b[N];
int cs[26], ca[26], cb[26], n, ans, tmp[26], cnta, cntb;

int main() {
	scanf("%s%s%s", s, a, b);
	n = strlen(s);
	for(int i = 0; s[i] != '\0'; ++i)
		cs[s[i] - 'a']++;
	for(int i = 0; a[i] != '\0'; ++i)
		ca[a[i] - 'a']++;
	for(int i = 0; b[i] != '\0'; ++i)
		cb[b[i] - 'a']++;
	int f = 0;
	for(int i = 0; i <= n; ++i) {
		int d = n;
		for(int j = 0; j < 26; ++j) {
			if(i)
				tmp[j] += ca[j];
			if(tmp[j] > cs[j]) {
				f = 1;
				break;
			}
			if(cb[j])
				d = min(d, (cs[j] - tmp[j]) / cb[j]);
		}
		if(f == 1)
			break;
		if(i + d > ans) {
			ans = i + d;
			cnta = i;
			cntb = d;
		}
	}
	for(int i = 0; i < cnta; ++i)
		printf("%s", a);
	for(int i = cnta; i < ans; ++i)
		printf("%s", b);
	for(int i = 0; i < 26; ++i) {
		cs[i] -= cnta * ca[i] + cntb * cb[i];
		assert(cs[i] >= 0);
		for(int j = 0; j < cs[i]; ++j)
			putchar('a' + i);
	}
	puts("");
	return 0;
}
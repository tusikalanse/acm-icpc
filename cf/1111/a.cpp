#include <bits/stdc++.h>
using namespace std;

int mp[1000];
char s[1010], t[1010];

int main() {
	scanf("%s%s", s, t);
	if(strlen(s) != strlen(t)) {
		puts("NO");
	}
	else {
		mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 1;
		for(int i = 0; s[i]; ++i) {
			if(mp[s[i]] != mp[t[i]]) {
				puts("NO");
				return 0;
			}
		}
		puts("YES");
	}
	return 0;
}
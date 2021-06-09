#include <bits/stdc++.h>
using namespace std;

int T;
char s[110], t[110], p[110];
int ls, lt, lp;
int cnt[30], vis[110];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s%s%s", s, t, p);
		memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		if(strlen(s) > strlen(t)) {
			puts("NO");
			continue;
		}
		ls = strlen(s), lt = strlen(t), lp = strlen(p);
		int i = 0, j = 0;
		for(; i < ls; ++i) {
			if(j >= lt) break;
			for(; j < lt; ++j) {
				if(s[i] == t[j]) {
					vis[i] = 1;
					++j;
					break;
				}
			}
		}
		if(vis[ls - 1] == 0) {
			puts("NO");
			continue;
		}
		for(int i = 0; i < lt; ++i) {
			cnt[t[i] - 'a']++;
		}
		for(int i = 0; i < ls; ++i) {
			cnt[s[i] - 'a']--;
		}
		for(int i = 0; i < lp; ++i) {
			cnt[p[i] - 'a']--;
		}
		bool flag = false;
		for(int i = 0; i < 26; ++i) {
			if(cnt[i] > 0)
				flag = true;
		}
		puts(flag ? "NO" : "YES");
	}
	return 0;
}
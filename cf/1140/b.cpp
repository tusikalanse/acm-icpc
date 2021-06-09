#include <bits/stdc++.h>
using namespace std;

int T, n, l, r;
char s[110];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%s", &n, s);
		l = r = 0;
		for(int i = 0; i < n; ++i) {
			if(s[i] == '<')
				l++;
			else
				break;
		}
		for(int i = n - 1; ~i; --i) {
			if(s[i] == '>')
				r++;
			else
				break;
		}
		printf("%d\n", min(l, r));
	}
	return 0;
}
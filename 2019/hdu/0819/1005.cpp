#include <bits/stdc++.h>
using namespace std;

int T, n;
char s[110];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		n = strlen(s);
		int p = 0;
		while(p < n && s[p] == 'y') p++;
		if(p < n && s[p] == 'z') s[p] = 'b';
		puts(s);
	}
	return 0;
}
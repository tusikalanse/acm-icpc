#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

char s[N];
int nxt[N];

void getnext() {
	nxt[0] = -1;
	int k = -1, j = 0;
	while(s[j]) {
		if(k == -1 || s[j] == s[k]) 
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int main() {
	while(~scanf("%s", s)) {
		int len = strlen(s);
		s[len++] = '~';
		scanf("%s", s + len);
		len = strlen(s);
		getnext();
		if(nxt[len]) {
			printf("%s %d\n", s + len-nxt[len], nxt[len]);
		}
		else
			puts("0");
	}
	return 0;
}


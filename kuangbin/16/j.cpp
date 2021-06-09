#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[100010];
int nxt[100010];


void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int k = -1, j = 0, m = strlen(s);
	while(j < m) {
		if(k == -1 || s[k] == s[j])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int main() {
	while(~scanf("%s", s)) {
		int len = strlen(s);
		s[len++] = '~';
		scanf("%s", &s[len]);
		len = strlen(s);
		getnext();
		if(nxt[len]) {
			printf("%s ", &s[len-nxt[len]]);
			printf("%d\n", nxt[len]);
		}
		else
			puts("0");
	}
	return 0;
}
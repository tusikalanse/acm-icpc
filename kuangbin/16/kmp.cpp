#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

void getnext(char *s, int *nxt) {
	nxt[0] = -1;
	int k = -1, j = 0;
	while(s[j]) {
		if(k == -1 || s[j] == s[k]) 
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int kmp(char *s, char *ls) {
	int nxt[MAXN];
	getnext(s, nxt);
	int i = 0, j = 0, cnt = 0, len = strlen(s);
	while(ls[i]) {
		if(j == -1 || ls[i] == s[j]) {
			++i;
			++j;
		}
		else
			j = nxt[j];
		if(j == len) {
			++cnt;
			j = nxt[j];
			//j = 0; //no cover
		}
	}
	return cnt;
}



int main() {
	char s[MAXN], ls[MAXN];
	scanf("%s%s", s, ls);
	printf("%d\n", kmp(s, ls));
	return 0;
}
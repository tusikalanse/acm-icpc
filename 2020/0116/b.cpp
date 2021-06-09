#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

char s[N], t[N];
int nxt[N];

void getnext() {
	nxt[0] = -1;
	int k = -1, j = 0;
	while(t[j]) {
		if(k == -1 || t[j] == t[k]) 
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int kmp() {
	getnext();
	int i = 0, j = 0, cnt = 0, len = strlen(t);
	while(s[i]) {
		if(j == -1 || s[i] == t[j]) {
			++i;
			++j;
		}
		else
			j = nxt[j];
		if(j == len) {
			++cnt;
			j = nxt[j];
		}
	}
	return cnt;
}

int main() {
	while(scanf("%s", s) && s[0] != '#' && scanf("%s", t)) {
		printf("%d\n", kmp());
	}
	return 0;
}
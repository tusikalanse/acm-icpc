#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
char s[N];
int nxt[N], n;
bool vis[N];

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int j = 0, k = -1;
	while(j < n) {
		if(k == -1 || s[j] == s[k])
			nxt[++j] = ++k;
		else 
			k = nxt[k];
	}
}


int main() {
	memset(vis, 0, sizeof(vis));
	scanf("%s", s);
	n = strlen(s);
	getnext();
	for(int i = 1; i < n; ++i)
		vis[nxt[i]] = 1;
	int p = nxt[n];
	while(p > 0) {
		if(vis[p]) {
			s[p] = '\0';
			printf("%s\n", s);
			return 0;
		}
		p = nxt[p];
	}
	puts("Just a legend");
	return 0;
}
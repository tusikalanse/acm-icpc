#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

char s[N];
int nxt[N], cnt;

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
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		getnext();
		int n = strlen(s), k = n - nxt[n];
		if(n % k == 0)
			printf("%d\n", n == k ? n : 0);
		else
			printf("%d\n", k - n % k);
	}
	return 0;
}

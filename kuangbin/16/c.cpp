#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char W[1010], T[1010];
int nxt[1010], cnt;

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int k = -1, j = 0, m = strlen(W);
	while(j < m) {
		if(k == -1 || W[k] == W[j])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int kmp() {
	getnext();
	int cnt = 0, i = 0, j = 0, n = strlen(T), m = strlen(W);
	while(i < n) {
		if(j == -1 || T[i] == W[j]) {
			++i;
			++j;
		}
		else
			j = nxt[j];
		if(j == m) {
			++cnt;
			j = 0;
		}
	}
	return cnt;
}

int main() {
	while(scanf("%s", T) && T[0] != '#' && scanf("%s", W)) {
		printf("%d\n", kmp());
	}
	return 0;
}

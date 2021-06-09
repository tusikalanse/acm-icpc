#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char W[10010], T[1000010];
int nxt[10010], cnt;

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
			j = nxt[j];
		}
	}
	return cnt;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s%s", W, T);
		printf("%d\n", kmp());
	}
	return 0;
}

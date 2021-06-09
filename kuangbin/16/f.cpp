#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char W[1000010];
int nxt[1000010], cnt;
int m;

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int k = -1, j = 0;
	while(j < m) {
		if(k == -1 || W[k] == W[j])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int main() {
	while(~scanf("%s", W)) {
		m = strlen(W);
		getnext();
		printf("%d\n", m - nxt[m]);
	}
	return 0;
}

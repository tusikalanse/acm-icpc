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
	int cas = 0;
	while(scanf("%d", &m) && m) {
		printf("Test case #%d\n", ++cas);
		scanf("%s", W);
		getnext();
		for(int i = 2; i <= m; ++i) {
			int k = i - nxt[i];
			if(i % k == 0 && nxt[i])
				printf("%d %d\n", i, i/k);
		}
		puts("");
	}
	return 0;
}

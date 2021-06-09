#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char W[100010];
int nxt[100010], cnt;

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

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", W);
		getnext();
		int n = strlen(W), k = n - nxt[n];
		if(n % k == 0 && n > k)
			printf("0\n");
		else if(n % k == 0)
			printf("%d\n", k);
		else
			printf("%d\n", k - n % k);
	}
	return 0;
}

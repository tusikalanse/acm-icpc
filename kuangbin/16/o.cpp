#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 1e6+10;

int nxt[MAXN];
char s[MAXN];

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int k = -1, j = 0, l = strlen(s);
	while(j < l) {
		if(k == -1 || s[j] == s[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int min_max(int flag) {
	int i = 0, j = 1, k = 0, len = strlen(s);
	while(i < len && j < len && k < len) {
		int t = s[(i+k)%len] - s[(j+k)%len];
		if(t == 0)
			++k;
		else {
			if(flag) {
				if(t > 0) {
					i += k + 1;
				}
				else {
					j += k + 1;
				}
			}
			else {
				if(t > 0) {
					j += k + 1;
				}
				else {
					i += k + 1;
				}
			}
			if(i == j)
				j++;
			k = 0;
		}
	}
	return min(i, j);
}


int main() {
	while(~scanf("%s", s)) {
		getnext();
		int len = strlen(s);
		int l = len - nxt[len];
		int sum;
		if(len % l == 0)
			sum = len / l;
		else
			sum = 1;
		int mmin = min_max(1), mmax = min_max(0);
		printf("%d %d %d %d\n", mmin + 1, sum, mmax + 1, sum);
	}

	return 0;
}
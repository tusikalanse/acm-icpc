#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[3] = {0, 1, 2}, ans, rec[3];
char s[N], t[5] = "RGB";


int main() {
	scanf("%d%s", &n, s);
	ans = n;
	do {
		int tmp = 0;
		for(int i = 0; i < n; ++i) {
			tmp += (s[i] != t[a[i % 3]]);
		}
		if(tmp < ans) {
			ans = tmp;
			memcpy(rec, a, sizeof(a));
		}
	} while(next_permutation(a, a + 3));
	printf("%d\n", ans);
	for(int i = 0; i < n; ++i) {
		printf("%c", t[rec[i % 3]]);
	}
	puts("");
	return 0;
}
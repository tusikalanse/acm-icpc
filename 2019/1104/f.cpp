#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

char s[N];

int T, n;
int cnt[6][6];

int main() {
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 6; ++i) {
			memset(cnt[i], 0, sizeof(cnt[i]));
			scanf("%s", s);
			n = strlen(s);
			for (int j = 0; j < n; ++j) {
				if (s[j] == 'h')
					cnt[i][0]++;
				if (s[j] == 'a')
					cnt[i][1]++;
				if (s[j] == 'r')
					cnt[i][2]++;
				if (s[j] == 'b')
					cnt[i][3]++;
				if (s[j] == 'i')
					cnt[i][4]++;
				if (s[j] == 'n')
					cnt[i][5]++;
			}
		}
		int a[6] = {0, 1, 2, 3, 4, 5};
		bool flag = false;
		do {
			int cc = 0;
			for (int i = 0; i < 6; i++)
				cc += !!cnt[i][a[i]];
			flag |= cc == 6;
		} while (!flag && next_permutation(a, a + 6));
		puts(flag ? "Yes" : "No");
	}
	return 0;
}
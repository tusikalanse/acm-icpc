#include <bits/stdc++.h>
using namespace std;

bool isp[5010][5010];
int ans[5010], n;
char s[5010];


int main() {
	scanf("%s", s + 1);
	memset(isp, 0, sizeof(isp));
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) {
		isp[i][i] = 1;
		for(int j = 1; j <= n; ++j) {
			if(i - j < 1 || i + j > n)
				break;
			if(s[i - j] != s[i + j])
				break;
			isp[i - j][i + j] = 1;
		}
	}
	for(int i = 1; i < n; ++i) {
		if(s[i] != s[i + 1])
			continue;
		isp[i][i + 1] = 1;
		for(int j = 1; j <= n; ++j) {
			if(i - j < 1 || i + 1 + j > n)
				break;
			if(s[i - j] != s[i + 1 + j])
				break;
			isp[i - j][i + 1 + j] = 1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			int k = 1, len = j - i + 1;
			while(isp[i][i + len - 1] && len) {
				ans[k]++;
				k++;
				len >>= 1;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
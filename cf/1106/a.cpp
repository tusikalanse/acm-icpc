#include <bits/stdc++.h>
using namespace std;


char g[510][510];

int n, ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%s", &g[i][1]);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(g[i][j] == 'X' && g[i - 1][j - 1] == 'X' && g[i - 1][j + 1] == 'X' && g[i + 1][j - 1] == 'X' && g[i + 1][j + 1] == 'X')
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
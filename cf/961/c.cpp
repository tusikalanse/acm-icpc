#include <bits/stdc++.h>
using namespace std;


int s[4][2] = {0};
char mp[4][102][102];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 4; i++) {
		for(int j = 1; j <= n; j++)
			scanf("%s", &mp[i][j][1]);
	}
	for(int k = 0; k < 4; k++) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
				if(((i + j) % 2 == 0) && mp[k][i][j] == '0')
					s[k][0]++;
				else if(((i + j) % 2 == 1) && mp[k][i][j] == '1')
					s[k][0]++;
				else
					s[k][1]++;
			}
	}
	int ans = s[0][0] + s[1][0] + s[2][1] + s[3][1];
	ans = min(ans, s[0][0] + s[1][1] + s[2][0] + s[3][1]);
	ans = min(ans, s[0][0] + s[1][1] + s[2][1] + s[3][0]);
	ans = min(ans, s[0][1] + s[1][0] + s[2][0] + s[3][1]);
	ans = min(ans, s[0][1] + s[1][0] + s[2][1] + s[3][0]);
	ans = min(ans, s[0][1] + s[1][1] + s[2][0] + s[3][0]);
	printf("%d\n", ans);
	return 0;
}
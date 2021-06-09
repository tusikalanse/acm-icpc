#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	char s[110];
	int dp[110][110];
	while(~scanf("%s", s)) {
		if(s[0] == 'e')
			break;
		memset(dp, 0, sizeof(dp));
		int len = strlen(s);
		for(int l = 1; l <= len; l++) {
			for(int i = 0; i + l <= len; i++) {
				int j = i + l - 1;
				if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
					dp[i][j] = dp[i+1][j-1] + 2;
				for(int k = i; k < j; k++)
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
		printf("%d\n", dp[0][len-1]);
	}


	return 0;
}
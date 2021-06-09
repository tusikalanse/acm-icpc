#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1006][1006];
char a[1000], b[1000];
int main(){
	while(~scanf("%s %s", a, b)){
		memset(dp, 0, sizeof(dp));
		int lena = strlen(a), lenb = strlen(b);
		for(int i = 1; i<=lena; i++)
			for(int j = 1; j<=lenb; j++){
				if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		printf("%d\n", dp[strlen(a)][strlen(b)]);	
	}	
	return 0;
}

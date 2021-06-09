#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct find{int sum, r;} res;
int dp[100006];
int a[100006];
int main(){
	int t, n;
	scanf("%d", &t);
	for(int p = 1; p<=t; p++){
		scanf("%d", &n);
		int l = 1;
		res.sum = res.r = 0;
		memset(dp, 0, sizeof(dp));
		printf("Case %d:\n", p);
		for(int i = 1; i<=n; i++) scanf("%d", a+i);
		for(int i = 1; i<=n; i++)
			if(dp[i-1] + a[i] >= 0) dp[i] = dp[i-1] + a[i];
			else dp[i] = 0;
		for(int i = 1; i<=n; i++)
			if(dp[i]>res.sum) {res.sum = dp[i]; res.r = i;} 
		if(res.sum == 0)
		{
			res.sum = -10000;
			for(int i = 1; i<=n; i++)
				if(a[i] > res.sum) { res.sum = a[i]; l = res.r = i;}
		}
		else{
			int i;
			for(i = res.r - 1; i >= 1; i--){
				if(dp[i] > 0) continue;
				else if (a[i] == 0) continue;
				else if (i!=1 && dp[i] == dp[i-1] +a[i]) continue;
				else { l = i+1; break;}
			}
			}	
		printf("%d %d %d\n", res.sum, l, res.r);
		if(p != t) puts("");	
	}
	return 0;
}

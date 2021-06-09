#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int dp[10][MAXN];

int F(int x){
	if(x < 10) return x;
	int res = 1;
	while(x){
		if(x%10)
			res *= (x%10);
		x /= 10;
	}
	return F(res);
}



void init(){
	for(int i = 0; i < MAXN; i++)
		dp[F(i)][i]++;
	for(int i = 1; i < 10; i++)
		for(int j = 1; j < MAXN; j++)
			dp[i][j] += dp[i][j-1];
}


int main(){
	int q, l, r, k;
	init();
	scanf("%d", &q);
	while(q--){
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", dp[k][r] - dp[k][l-1]);
	}
	return 0;
}
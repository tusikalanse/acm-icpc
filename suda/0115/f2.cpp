#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n, i, m = 1;
	int dp[1003], a[1003];
	scanf("%d" ,&n);
	for(i = 0; i<n; i++){ 
		scanf("%d", a+i);
		dp[i] = 1;
		for(int j = 0; j<i; j++)
			if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);	
		m = max(m, dp[i]);
	} 
	printf("%d\n", m);	
	return 0;
}

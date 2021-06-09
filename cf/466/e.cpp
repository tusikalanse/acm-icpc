#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100006;

long long dp[MAXN], sum[MAXN], a[MAXN];


int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 1; i<=n; i++){
		scanf("%lld", &a[i]);
		dp[i] =  sum[i] = sum[i-1] + a[i];
	}
	multiset<long long> s;
	for(int i = 1; i<c; i++)
		s.insert(a[i]);
	for(int i = c; i<=n; i++){
		s.insert(a[i]);
		dp[i] = min(dp[i-1] + a[i], dp[i-c] + sum[i] - sum[i-c] - *s.begin());
		s.erase(s.find(a[i-c+1]));
	}
	printf("%lld\n", dp[n]);
	return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100006];
int main(){
	int t, n ,s;
	scanf("%d", &t);
	while(t--){
		memset(a, 0, sizeof(a));
		scanf("%d %d", &n, &s);
		int l = 1, r = 2, ans = 1e7, sum = 0;
		for(int i = 1; i<=n; i++)
			scanf("%d", a+i);
		sum = a[1];
		while(l<=n && r<=n+1){ 
			if(sum+a[r] < s) sum += a[r++];
			else
			{
			ans = min(ans, r-l+1);
			sum -= a[l++];	
			}
		}
		if (ans == (int)1e7) ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}

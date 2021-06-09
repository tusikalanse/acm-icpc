#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[105], n, t;
	scanf("%d %d", &n, &t);
	for(int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	int cnt = 0, ans = 0;
	for(int i = 0; i<n; i++){
		cnt = 0;
		for(int j = i; j<n; j++){
			if(a[j] - a[i] <= t)
				cnt++;
			else 
				break;
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", n-ans);
	return 0;
}
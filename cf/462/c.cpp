#include <bits/stdc++.h>
using namespace std;
int n, a[2005];

int BinarySearch(int x, int list[], int l, int r){
	int mid = (l+r)/2;
	if(l == r) return l;
	if (list[mid] <= x  && x < list[mid+1]) return mid;
	else if(list[mid] > x) return BinarySearch(x, list, l, mid);
	else return BinarySearch(x, list, mid+1, r);	
}


int calc(int x, int y){
	int dp[2005];
	for(int i = x; i<=y+1; i++) dp[i] = 3000;
	dp[x-1] = -1;
	dp[x] = a[x];
	int m = 1;
	for(int i = x+1; i<=y; i++){
		int k = BinarySearch(a[i], dp, x, x+m);
		dp[k+1] = a[i];	
		m = max(k+1-(x-1), m);	
	}
	return m;
}

int main(){
	int res = 0;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for(int i = 1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i<n; i++){
		res = max(res, calc(1, i) + calc(i + 1, n));
	}
	printf("%d\n", res);
	return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;



int BinarySearch(int x, int list[], int l, int r){
	int mid = (l+r)/2;
	if (list[mid] <= x  && x < list[mid+1]) return mid;
	else if(list[mid] > x) return BinarySearch(x, list, l, mid);
	else return BinarySearch(x, list, mid+1, r);	
}
int main(){
	int n, i, m;
	int dp[1003], a[1003];
	scanf("%d" ,&n);
	for(i = 1; i<=n; i++) scanf("%d", a+i);
	memset(dp, 9, sizeof(a));
	dp[0] = -1;
	dp[1] = 1;
	m = 1;
	for(i = 2; i<=n; i++){
		int k = BinarySearch(a[i], dp, 1, m);
		dp[k+1] = a[i];	
		m = max(k+1, m);	
	}
	printf("%d\n", m);	
	return 0;
}

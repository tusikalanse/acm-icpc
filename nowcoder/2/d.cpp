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
	int dp[103], a[103];
	scanf("%d" ,&n);
	for(i = 1; i<=n; i++) scanf("%d", a+i);
	if(n<30){ m = 1; goto nxt;}
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0] = -0x3f3f3f3f;
	dp[1] = a[1];
	m = 1;
	for(i = 2; i<=n; i++){
		int k = BinarySearch(a[i], dp, 1, m);
		dp[k+1] = a[i];	
		m = max(k+1, m);	
	}
	nxt:;
	puts(m>=30?"yes":"no");	
	return 0;
}

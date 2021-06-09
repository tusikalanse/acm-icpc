#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#define MAXN 100007
using namespace std;
int T;
struct node{
	int val, index;
	bool operator<(const node &rhs)const{
		return val+T*index<rhs.val+T*rhs.index;
	}
}arr[MAXN];


int main(){
	int n, s;
	long long pre = 0, ans;
	scanf("%d %d", &n, &s);
	for(int i = 1; i<=n; i++){
		scanf("%d", &arr[i].val);
		arr[i].index = i;
	}
	int l = 0, r = n;
	while(l <= r){
		int i = (l+r)>>1;
		T = i;
		ans = 0;
		nth_element(arr+1, arr+i, arr+1+n);
		for(int j = 1; j<=i; j++) ans += 1LL*arr[j].val+1LL*T*arr[j].index; 
		if (ans > s) {r = i-1;}
		else {pre = ans; l = i+1;}
	}
	printf("%d %lld\n", r, pre);
	
	
	return 0;
}

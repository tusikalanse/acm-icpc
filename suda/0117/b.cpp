#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;



double a[10006];
int n,k;
double l = 0.00, r = 100000, mid;
int check(){
	int count = 0;
	for(int i = 0; i<n; i++)
		count += (int)(a[i]/mid);
	if (count >= k) return 1;
	return 0;	
}

int main(){
	while(~scanf("%d %d", &n, &k)){
	l = 0.00, r = 100000;
	for(int i = 0; i<n; i++) scanf("%lf", a+i);
	for(int i = 1; i<1000; i++){
		mid = (l+r)/2;
		if (check()) l = mid;
		else r = mid;		
	}
	printf("%0.2f\n", floor(mid*100)/100);
	}	
	return 0;
}

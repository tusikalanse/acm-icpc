#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	for(int i = 1; i <= 200; i++){
		for(int j = 1; j < i; j++){
			for(int k = 1; k < j; k++){
				if(	a <= i && 2 * a >= i && 
					b <= j && 2 * b >= j && 
					c <= k && 2 * c >= k &&
					d <= k && 2 * d >= k && 2 * d < j){
					printf("%d\n%d\n%d\n", i, j, k);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}
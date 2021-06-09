#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for(int i = 200; i >= 0; i--) {
		for(int j = i - 1; j >= 0; j--) {
			for(int k = j - 1; k >= 0; k--) {
				if(a <= i && 2 * a >= i && b <= j && 2 * b >= j && c <= k && 2 * c >= k && d <= k && 2 * d >= k && 2 * d < j) {
					printf("%d\n%d\n%d\n", i, j, k);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0; 
}
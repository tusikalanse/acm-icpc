#include <bits/stdc++.h>
using namespace std;

int k, tot;

int main() {
	scanf("%d", &k);
	tot = k + 2000;
	printf("2000\n-1 ");
	for(int i = 2; i <= 2000; ++i) {
		if(tot > 1000000) {
			printf("%d", 1000000);
			tot -= 1000000;
		}
		else {
			printf("%d", tot);
			tot -= tot;
		}
		printf("%c", " \n"[i == 2000]);
	}
	return 0;
}
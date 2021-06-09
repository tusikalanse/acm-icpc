#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &n, &k);
		if (n == 0){
			printf("0\n");
			continue;
		}
		for (int i = 1; i <= k; ++i){
			n = (n - 1) / 2 + 1;
			if (n == 1)
				break;
		}
		printf("%d\n", n);
	}
}
#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main() {
	int n;
	int flag = 0;
	int dep = 0;
	cin >> n;
	for(int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
		flag |= (i != 0 && a[i] != 1 && a[i-1] != 1);
		if(dep == 0 && i != 0 && a[i] != 1 && a[i-1] != 1)
			dep = i;
	}
	if(flag) {
		puts("ambiguous");
		int sum = 0;
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j < a[i]; j++) 
				printf("%d ", sum);
			sum += a[i];
		}
		puts("");
		sum = 0;
			int f = 1;
			for(int i = 0; i <= n; i++) {
				for(int j = 0; j < a[i]; j++) {
					if(i == dep && f) {
						f = 0;
						printf("%d ", sum - 1);
					}
					else
						printf("%d ", sum);
				}
				sum += a[i];
			}

		puts("");
	}
	else
		puts("perfect");
	return 0;
}
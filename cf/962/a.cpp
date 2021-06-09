#include <bits/stdc++.h>
using namespace std;


int a[200010];
long long sum = 0, tmp = 0;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for(int i = 1; i <= n; i++) {
		tmp += a[i];
		if(tmp >= (sum-1)/2+1) {
			printf("%d\n", i);
			return 0;
		}
	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, n, k;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		if(k % 3 != 0) {
			puts(n % 3 == 0 ? "Bob" : "Alice");
		}
		else {
			puts(n % (k + 1) % 3 == 0 && (n + 1) % (k + 1) != 0 ? "Bob" : "Alice");
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 52529, cnt = 0; cnt < n; cnt++, i += 710) {
		printf("%d\n", i);
	}
	return 0;
}
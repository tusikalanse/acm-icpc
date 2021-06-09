#include <bits/stdc++.h>
using namespace std;

int T, a[1010], n;
int ans[] = {0, 0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		if(((n + 1) & n) == 0) {
			int cnt = 0;
			n++;
			while(n) {
				cnt++;
				n >>= 1;
			}
			printf("%d\n", ans[cnt]);
		}
		else {
			int l = 1;
			while(n >= l)
				l *= 2;
			printf("%d\n", l - 1);
		}
	}
	return 0;
}
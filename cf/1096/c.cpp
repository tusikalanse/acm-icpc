#include <bits/stdc++.h>
using namespace std;


const int N = 180;

int ans[N];
int T, q;

bool eps(int j, int i) {
	double eg = 180.0 / j;
	double ans = i / eg;
	return abs(ans - (int)ans) < 1e-8;
}


int main() {
	for(int i = 1; i <= 180; ++i) {
		for(int j = 3; j <= 360; ++j) {
			if(eps(j, i) && 180 * j - 360 >= i * j) {
				ans[i] = j;
				break;
			}
		}
	}
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &q);
		printf("%d\n", ans[q]);
	}
	return 0;
}
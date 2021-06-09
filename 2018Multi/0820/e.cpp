#include <bits/stdc++.h>
using namespace std;

int T, n, m, R;
double stu[205][2], bu[205][2];
double ans[205], w;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &R);
		for(int i = 1; i <= n; ++i)
			scanf("%lf%lf", &bu[i][0], &bu[i][1]);
		for(int i = 1; i <= m; ++i) {
			scanf("%lf%lf", &stu[i][0], &stu[i][1]);
			ans[i] = 1e18;
			for(int j = 1; j <= n; ++j) {
				double tmp = hypot(abs(bu[j][0] - stu[i][0]), abs(bu[j][1] - stu[j][1]));
				if(tmp <= R) 
					tmp = 0;
				else
					tmp -= R;
				ans[i] = min(ans[i], tmp);
			}
			// w += ans[i];
			printf("%d\n", (int)(ans[i] + 0.5));
		}
		// printf("%d\n", (int)(w + 0.5));
	}

	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct node{
	double t, x;
	bool operator < (const node &rhs) {
		return t < rhs.t;
	}
}a[10005];

int main() {
	int T, n, cas = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%lf%lf", &a[i].t, &a[i].x);
		}
		sort(a + 1, a + n + 1);
		double ans = 0;
		for(int i = 1; i < n; i++) {
			ans = max(ans, fabs((a[i+1].x-a[i].x)/(a[i+1].t-a[i].t)));
		}
		printf("Case #%d: %.2lf\n", ++cas, ans);
	}
	return 0;
}
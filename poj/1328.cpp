#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct Island
{
	double x, y, l, r;
	bool operator < (const Island &rhs) const {
		return l < rhs.l;
	}
}island[1010];



int main() {
	int n, d, flag, cas = 0;
	double delta;
	while(~scanf("%d %d", &n, &d) && n && d) {
		flag = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lf %lf", &island[i].x, &island[i].y);
			if(island[i].y > d)
				flag = 1;
			else {
				delta = sqrt(d*d - island[i].y*island[i].y);
				island[i].l = island[i].x - delta;
				island[i].r = island[i].x + delta;
			}
		}
		if(flag) {
			printf("Case %d: -1\n", ++cas);
			continue;
		}
		sort(island + 1, island + n + 1);
		int ans = 1;
		double pos = island[1].r;
		for(int i = 2; i <= n; i++) {
			if(pos >= island[i].l)
				pos = min(pos, island[i].r);
			else {
				ans++;
				pos = island[i].r;
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
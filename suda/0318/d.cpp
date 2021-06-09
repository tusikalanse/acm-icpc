#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;


double a[100005], b[100005];
int main(){
	int t, cas = 0;
	int n, m;
	double c, d;
	scanf("%d", &t);
	while(t--){
		scanf("%lf %lf", &c, &d);
		scanf("%d %d", &n, &m);
		double ans = 0, h = (c - d) * (c - d);
		for(int i = 0; i<n; i++) scanf("%lf", &a[i]);
		for(int i = 0; i<m; i++) scanf("%lf", &b[i]);
		int x = 0, y = 0;
		while(x < n && y < m){
			ans += sqrt(h + (a[x] - b[y]) * (a[x] - b[y]));
			if(x == n-1) y++;
			else if(y == m-1) x++;
			else{
				if(abs(a[x] - b[y+1]) < abs(a[x+1] - b[y]))
					y++;
				else 
					x++;
			}
		}
		printf("Case #%d: %.2lf\n", ++cas, ans);
	}
	return 0;
}
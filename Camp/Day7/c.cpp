#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

struct line {
	double k, b;
}high[N], low[N], h[N], l[N];

int n, cnthigh, cntlow;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &high[i].k, &high[i].b);
		low[i] = high[i];
	}
	sort(high + 1, high + n + 1, [](line &i, line &j) {return i.k == j.k ? i.b > j.b : i.k < j.k;});
	sort(low + 1, low + n + 1, [](line &i, line &j) {return i.k == j.k ? i.b < j.b : i.k > j.k;});
	h[++cnthigh] = high[1], l[++cntlow] = low[1];
	for(int i = 2; i <= n; ++i) {
		if(high[i].k != h[cnthigh].k)
			h[++cnthigh] = high[i];
		if(low[i].k != l[cntlow].k)
			l[++cntlow] = low[i];
	}
	if(cnthigh == 1) {
		if(n == 1)
			printf("%.15f\n", 0.0); 
		else {
			double mx = -1e100, mn = 1e100;
			for(int i = 1; i <= n; ++i) { 
				mx = max(mx, high[i].b);
				mn = min(mn, high[i].b);
			}
			printf("%.15f\n", mx - mn);
		}
		return 0;
	}
	double ans = 1e100;
	int i = 1, j = 2;
	double xi, xj = (l[2].b - l[1].b) / (l[1].k - l[2].k);
	for(i = 2; i <= cnthigh; ++i) {
		xi = (h[i].b - h[i - 1].b) / (h[i - 1].k - h[i].k);
		while(j <= cntlow && xj < xi) {
			j++;
			xj = (l[j].b - l[j - 1].b) / (l[j - 1].k - l[j].k);
		}
		if(j == cntlow && xj < xi)
			j = cntlow + 1; 
		double mx = h[i].k * xi + h[i].b;
		double mn = l[j - 1].k * xi + l[j - 1].b;
		ans = min(ans, mx - mn);
	}
	i = 2, j = 2;
	xi = (h[2].b - h[1].b) / (h[1].k - h[2].k);
	for(j = 2; j <= cntlow; ++j) {
		xj = (l[j].b - l[j - 1].b) / (l[j - 1].k - l[j].k);
		while(i <= cnthigh && xi < xj) {
			i++;
			xi = (h[i].b - h[i - 1].b) / (h[i - 1].k - h[i].k);
		}
		if(i == cnthigh && xi < xj)
			i = cnthigh + 1; 
		double mx = h[i - 1].k * xj + h[i - 1].b;
		double mn = l[j].k * xj + l[j].b;
		ans = min(ans, mx - mn);
	}
	printf("%.15f\n", ans);
	return 0;
}
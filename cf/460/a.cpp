#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	double x, y, ans;
	int m, n;
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++){
		scanf("%lf %lf", &x, &y);
		if(i == 0)
			ans = x/y;
		else
			ans = min(ans, x/y);
	}
	printf("%lf\n", ans*m);
	return 0;
}
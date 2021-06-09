#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double p1 = double(a)/b, p2 = double(c)/d, ans = 0, q = 1;
	ans = p1/(p1+p2-p1*p2);
	cout << ans << endl;

	return 0;
}
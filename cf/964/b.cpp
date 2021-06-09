#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c, t;
	int tt[1110];
	int ans = 0;
	cin >> n >> a >> b >> c >> t;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &tt[i]); 
		if(b > c)
			ans += a;
		else
			ans += (a + (c - b) * (t - tt[i]));
	}
	cout << ans << endl;


	return 0;
}
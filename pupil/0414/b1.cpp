#include <bits/stdc++.h>
using namespace std;


int a[1010];
int main() {
	int n, x, y;
	cin >> n;
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		a[x]++;
		a[y]++;
	}
	int ans = 0;
	for(int i =1; i <= n; i++) 
		ans += (a[i] == 1);
	cout << ans << endl;
	return 0;
}
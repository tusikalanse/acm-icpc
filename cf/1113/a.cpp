#include <bits/stdc++.h>
using namespace std;


int n, v, ans;

int main() {
	cin >> n >> v;
	for(int i = 1; i < n; ++i) 
		ans += max(1, 1 + i - v);
	cout << ans << endl;
	return 0;
}
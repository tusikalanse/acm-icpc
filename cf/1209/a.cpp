#include <bits/stdc++.h>
using namespace std;

int n, ans, a[110], vis[110];

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) continue;
		vis[i] = 1;
		ans++;
		for(int j = i; j <= n; ++j)
			if(a[j] % a[i] == 0)
				vis[j] = 1;
	}
	cout << ans << endl;
	return 0;
}
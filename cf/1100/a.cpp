#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[110], b[110];


int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) 
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= k; ++i) {
		memcpy(b, a, sizeof(b));
		int ca = 0, cb = 0;
		for(int j = 1; j <= n; ++j)
			if((j - i) % k == 0) 
				b[j] = 0;
		for(int j = 1; j <= n; ++j)
			if(b[j] == 1)
				ca++;
			else if(b[j] == -1)
				cb++;
		ans = max(ans, abs(ca - cb));
	}
	cout << ans << endl;
	return 0;
}
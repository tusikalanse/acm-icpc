#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5 + 10;
char a[N], b[N];
LL n, a1, a0, b1, b0, ans;

int main() {
	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i) {
		if(a[i] == '1')
			a1++;
		else
			a0++;
	}
	for(int i = 0; i < n; ++i) {
		if(b[i] == '0') {
			if(a[i] == '1') {
				ans += a0;
				b1++;
			}
			else {
				ans += a1;
				b0++;
			}
		}
	}
	ans -= b0 * b1;
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool f[31];
int n, m, t, l, r, mid;

int main() {
	cin >> m >> n;
	cout << m << endl;
	cin >> t;
	if(t == 0)
		return 0;
	f[0] = t == -1;
	for(int i = 1; i < n; ++i) {
		cout << m << endl;
		cin >> t;
		f[i] = t == -1;
	}
	l = 1, r = m;
	for(int i = 0; i < 30; ++i) {
		mid = l + r >> 1;
		cout << mid << endl;
		cin >> t;
		if(t == 0)
			return 0;
		if(t == 1) {
			if(f[i % n])
				l = mid + 1;
			else
				r = mid - 1;
		}
		else {
			if(f[i % n])
				r = mid - 1;
			else 
				l = mid + 1;
		}
	}
	return 0;
}
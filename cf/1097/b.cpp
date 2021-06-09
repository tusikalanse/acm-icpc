#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k, a[20];
	bool flag = 0;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < (1 << n); ++i) {
		int tmp = 0;
		for(int j = 0; j < n; ++j) {
			if((1 << j) & i)
				tmp += a[j];
			else
				tmp -= a[j];
		}
		if(tmp < 0)
			tmp = -tmp;
		flag |= tmp % 360 == 0;
	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}
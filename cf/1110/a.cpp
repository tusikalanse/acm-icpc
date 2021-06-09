#include <bits/stdc++.h>
using namespace std;

int a[1000010], b, k;

int main() {
	bool flag = 0;
	cin >> b >> k;
	for(int i = 1; i <= k; ++i) {
		cin >> a[i];
		if(i != k)
			flag ^= (a[i] & 1) & (b & 1);
		else 
			flag ^= (a[i] & 1);
	}
	if(flag)
		cout << "odd" << endl;
	else
		cout << "even" << endl;
	return 0;
}
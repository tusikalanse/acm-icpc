#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n;

bool ask(int i) {
	int a, b;
	cout << "? " << i << endl;
	cout << "? " << i + n / 2 << endl;
	cin >> a >> b;
	if(a == b) {
		cout << "! " << i << endl;
		exit(0);
	}
	return a < b;
}


int main() {
	cin >> n;
	if(n % 4 != 0) {
		cout << "! -1" << endl;
		return 0;
	}
	int l = 1, r = 1 + n / 2, mid;
	int st = ask(1);
	while(1) {
		mid = l + r >> 1;
		if(ask(mid) == st)
			l = mid;
		else
			r = mid;
	}
	return 0;
}
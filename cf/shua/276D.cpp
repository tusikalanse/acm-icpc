#include <bits/stdc++.h>
using namespace std;


int main() {
	long long a, b;
	cin >> a >> b;
	int i;
	for(i = 59; ~i; --i) {
		if((a & (1LL << i)) != (b & (1LL << i)))
			break;
	}
	cout << ((1LL << (i + 1)) - 1) << endl; 
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int x, y, n, d;
multiset<int> m;

int main() {
	cin >> n;
	while(n--) {
		cin >> d;
		m.insert(d);
	}
	x = *m.rbegin();
	for(int i = 1; i <= x; ++i) {
		if(x % i == 0)
			m.erase(m.find(i));
	}
	y = *m.rbegin();
	cout << x << " " << y << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int l, r;

bool check(int x) {
	set<int> s;
	int cnt = 0;
	while(x) {
		s.insert(x % 10);
		x /= 10;
		cnt++;
	}
	return cnt == s.size();
}

int gao() {
	for(int i = l; i <= r; ++i) {
		if(check(i)) return i;
	}
	return -1;
}

int main() {
	cin >> l >> r;
	cout << gao() << endl;
	return 0;
}
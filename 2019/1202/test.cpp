#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> m;
	m[3] = 5;
	int c = 9;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
		m[c++] = 10;
	}
	return 0;
}
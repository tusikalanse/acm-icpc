#include <bits/stdc++.h>
using namespace std;

char s[10], t[10];

int main() {
	bool flag = 0;
	cin >> s;
	cin >> t;
	flag |= s[0] == t[0];
	flag |= s[1] == t[1];
	cin >> t;
	flag |= s[0] == t[0];
	flag |= s[1] == t[1];
	cin >> t;
	flag |= s[0] == t[0];
	flag |= s[1] == t[1];
	cin >> t;
	flag |= s[0] == t[0];
	flag |= s[1] == t[1];
	cin >> t;
	flag |= s[0] == t[0];
	flag |= s[1] == t[1];
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
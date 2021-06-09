#include <bits/stdc++.h>
using namespace std;



int main() {
	string s;
	cin >> s;
	int c1 = 0, c0 = 0, f = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '0')
			c0++;
		if(s[i] == '2')
			break;
	}
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '1')
			c1++;
	}
	for(int i = 0; i < c0; ++i)
		cout << 0;
	for(int i = 0; i < c1; ++i)
		cout << 1;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '2')
			f = 1;
		if(f == 0)
			continue;
		if(s[i] != '1')
			cout << s[i];
	}
	cout << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;


int main() {
	cin >> T;
	while(T--) {
		cin >> s;
		n = s.size();
		if(s[n - 1] == 'a' || s[n - 1] == 'o' || s[n - 1] == 'u') 
			s += "s";
		else if(s[n - 1] == 'i' || s[n - 1] == 'y')
			s = s.substr(0, n - 1) + "ios";
		else if(s[n - 1] == 'l' || s[n - 1] == 'r' || s[n - 1] == 'v')
			s += "es";
		else if(s[n - 1] == 'n') 
			s = s.substr(0, n - 1) + "anes";
		else if(n >= 2 && s[n - 2] == 'n' && s[n - 1] == 'e')
			s = s.substr(0, n - 2) + "anes";
		else if(s[n - 1] == 't' || s[n - 1] == 'w')
			s += "as";
		else 
			s += "us";
		cout << s << endl;
	}
	return 0;
}
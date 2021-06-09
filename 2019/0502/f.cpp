#include <bits/stdc++.h>
using namespace std;


int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		cout << s[0];
		for(int i = 1; i < s.size(); ++i)
			if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y')
				cout << s[i];
		cout << endl;
	}
	return 0;
}
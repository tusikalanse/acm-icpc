#include <bits/stdc++.h>
using namespace std;

int main() {
	set<char> v;
	v.insert('a');
	v.insert('e');
	v.insert('i');
	v.insert('o');
	v.insert('u');
	bool flag = 1;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == 'n')
			continue;
		if(find(v.begin(), v.end(), s[i]) == v.end()) {
			if(i == s.size() - 1) {
				flag = 0;
				break;
			}
			if(find(v.begin(), v.end(), s[i + 1]) == v.end()) {
				flag = 0;
				break;
			}
		}
	}	
	puts(flag ? "YES" : "NO");

	return 0;
}
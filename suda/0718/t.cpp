#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string s[1010];

int main() {
	int n = 0;
	while(cin >> s[n]) {
		mp[s[n]] = 1;
		n++;
	}
	for(int i = 0; i < n; ++i)
		for(int j = 1; j < s[i].size() - 1; ++j)
			if(mp[s[i].substr(0, j)] && mp[s[i].substr(j, s[i].size() - j)] && s[i].substr(0, j) != s[i].substr(j, s[i].size() - j))
				{cout << s[i] << endl; 
					break;}

	return 0;
}
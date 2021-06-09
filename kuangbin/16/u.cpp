#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int Manacher(string s) {
	string t = "$#";
	for(int i = 0; i < s.size(); ++i) {
		t += s[i];
		t += '#';
	}
	vector<int> p(t.size(), 0);
	int mx = 0, id = 0, reslen = 0, resid = 0;
	for(int i = 0; i < t.size(); ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while(t[i + p[i]] == t[i - p[i]])
			++p[i];
		if(mx < i + p[i]) {
			mx = i + p[i];
			id = i;
		}
		if(reslen < p[i]) {
			reslen = p[i];
			resid = i;
		}
	}
	return reslen - 1;
}

int main() {
	string s;
	int cas = 0;
	while(cin >> s) {
		if(s == "END")
			break;
		printf("Case %d: %d\n", ++cas, Manacher(s));
	}
	return 0;
}
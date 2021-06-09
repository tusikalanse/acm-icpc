#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	bool flag = true;
	cin >> s;
	for(int i = 0; i < s.size() - 1; ++i)
		if(s[i] == s[i + 1]) {
			flag = false;
			break;
		}
	puts(flag ? "Odd." : "Or not.");
	return 0;
}
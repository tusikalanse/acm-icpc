#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string a, b;

string gao(string s) {
	if(s.size() % 2 == 1)
		return s;
	string x = gao(s.substr(0, s.size() / 2)), y = gao(s.substr(s.size() / 2, s.size() / 2));
	if(x < y) 
		return x + y;
	else
		return y + x;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	puts(gao(a) == gao(b) ? "YES" : "NO");
	return 0;
}
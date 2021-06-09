#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

string s[N];
int n;

bool cmp(string &a, string &b) {
	return a + b < b + a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	sort(s, s + n, cmp);
	for(int i = 0; i < n; ++i)
		cout << s[i];
	cout << endl;
	return 0;
}
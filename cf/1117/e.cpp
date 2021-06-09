#include <bits/stdc++.h>
using namespace std;

string s[3], t[3], ss, tt;
int f[10010];
int n;

int main() {
	cin >> ss;
	n = ss.size();
	for(int i = 0; i < n; ++i) {
		int p = i;
		s[2] += 'a' + p % 26;
		p /= 26;
		s[1] += 'a' + p % 26;
		p /= 26;
		s[0] += 'a' + p;
	}
	cout << "? " << s[0] << endl;
	cout << "? " << s[1] << endl;
	cout << "? " << s[2] << endl;
	cin >> t[0] >> t[1] >> t[2];
	for(int i = 0; i < n; ++i) {
		int num = 0;
		num += t[0][i] - 'a';
		num *= 26;
		num += t[1][i] - 'a';
		num *= 26;
		num += t[2][i] - 'a';
		f[num] = i;
	}
	for(int i = 0; i < n; ++i)
		tt += ss[f[i]];
	cout << "! " << tt << endl;
	return 0;
}
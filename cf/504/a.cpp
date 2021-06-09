#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
char s[N], t[N];
int id = -1, l, r;

int main() {
	cin >> n >> m >> s >> t;
	for(int i = 0; i < n; ++i) 
		if(s[i] == '*')
			id = i;
	if(id == -1 || n - 1 > m) {
		if(strcmp(s, t) == 0)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	else {
		l = 0;
		for(int i = 0; s[i] == t[i]; ++i, ++l);
		r = n - 1;
		for(int i = 0; s[n - 1 - i] == t[m - 1 - i]; ++i, --r);
		if(l == id && r == id)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}
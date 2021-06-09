#include <bits/stdc++.h>
using namespace std;

int mat[60][60];

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a--,b--,c--,d--;
	cout << 50 << ' ' << 50 << endl;
	for(int i = 0; i < 12; ++i)
		for(int j = 0; j < 50; ++j)
			mat[i][j] = 0;
	for(int i = 12; i < 24; ++i)
		for(int j = 0; j < 50; ++j)
			mat[i][j] = 1;
	for(int i = 24; i < 36; ++i)
		for(int j = 0; j < 50; ++j)
			mat[i][j] = 2;
	for(int i = 36; i < 50; ++i)
		for(int j = 0; j < 50; ++j)
			mat[i][j] = 3;
	for(int i = 0; i < 12; i += 2) {
		for(int j = 0; j < 50; j += 2)
			if(b > 0) {
				mat[i][j] = 1;
				b--;
			}
	}
	for(int i = 12; i < 24; i += 2) {
		for(int j = 0; j < 50; j += 2)
			if(c > 0) {
				mat[i][j] = 2;
				c--;
			}
	}
	for(int i = 24; i < 36; i += 2) {
		for(int j = 0; j < 50; j += 2)
			if(d > 0) {
				mat[i][j] = 3;
				d--;
			}
	}
	for(int i = 36; i < 50; i += 2) {
		for(int j = 0; j < 50; j += 2)
			if(a > 0) {
				mat[i][j] = 0;
				a--;
			}
	}
	for(int i = 0; i < 50; ++i) {
		for(int j = 0; j < 50; ++j)
			cout << (char)('a' + mat[i][j]);
		cout << endl;
	}

	return 0;
}

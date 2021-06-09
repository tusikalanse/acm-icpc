#include <bits/stdc++.h>
using namespace std;

int m[2000][2000];

int main() {
	srand(time(NULL));
	memset(m, 0, sizeof(m));
	int n = 2000, p, q;
	cout << 2000 << endl;
	while(n--) {
		do {
			p = rand() % 2000;
			q = rand() % 2000;
		} while(m[p][q]);
		m[p][q] = 1;
	}
	for(int i = 0; i < 2000; ++i) {
		for(int j = 0; j < 2000; ++j) {
			putchar('0' + m[i][j]);
		}
		cout << endl;
	}
	return 0;
}
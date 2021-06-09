#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int n = 5, m = 5;
	cout << n << " " << m << endl;
	for(int i = 0; i < n; ++i)
		if (rand() % 2)
			cout << 'A';
		else
			cout << 'B';
	cout << endl;
	for(int i = 1; i <= m; ++i) {
		int opt = rand() % 2, l = 1 + rand() % 5, r = 1 + rand() % 5;
		if (l > r) swap(l, r);
		cout << opt + 1 << " " << l << " " << r << " ";
		if(opt) {
			int A = rand() % 10, B = rand() % 10;
			cout << A << " " << B;
		}
		cout << endl;
	}
	return 0;
}

/*
5 8
00110
2 2 4
4 1 3
4 2 3
1 1 4
2 2 3
4 3 4
3 1
4 1 2
*/
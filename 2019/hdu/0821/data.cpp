#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	cout << 1 << endl;
	cout << 300000 << endl;
	for(int i= 1; i <= 300000; ++i)
		cout << 1 + rand() % 2 << " ";
	cout << endl;
	return 0;
}
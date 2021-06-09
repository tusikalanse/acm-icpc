#include <bits/stdc++.h>
using namespace std;

int a[100010];

int gg(int n) {
	for (int i = 1; i <= n; ++i) a[i] = i;
	random_shuffle(a + 1, a + n + 1);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		while (a[i] != i) random_shuffle(a + i, a + n + 1), res++;
	}

	return res;
}

double fuck(int n) {
	double res = 0;
	for (int i = 1; i <= 100000; ++i)
		res += gg(n);
	return res / 100000;
}

double gao(int n) {
	double res = 0;
	for(int i = 1; i <= n; ++i) res += fuck(i);
	return res;
}

int main() {
	srand(time(NULL));
	for (int i = 1; i <= 10; ++i) 
		cout << i << " " << gao(i) << endl;
	return 0;
}
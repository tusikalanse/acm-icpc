#include <bits/stdc++.h>
using namespace std;

int a[110];

int foo(int num) {
	for (int i = 1; i <= num; ++i) a[i] = i;
	random_shuffle(a + 1, a + num + 1);
	int cnt = 0;
	for (int i = 1; i <= num; ++i) {
		while (a[i] != i) {
			++cnt;
			random_shuffle(a + i, a + num + 1);
		}
	}
	return cnt;
}

double gao(int num) {
	double tot = 0;
	for (int i = 1; i <= 100000; ++i) tot += foo(num);
	return tot / 100000;
}

int main() {
	srand(time(NULL));
	for (int i = 1; i <= 40; ++i)
		cout << "gao(" << i << ") = " << gao(i) << endl;
	return 0;
}
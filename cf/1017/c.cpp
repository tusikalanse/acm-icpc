#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, down, up, len;
bool flag = 0;
int main() {
	cin >> n;
	down = sqrt(n);
	up = down + 1;
	if(n > 1) {
		if(((n / down) + down + n % down) > ((n / up) + up + (n % up > 0))) {
			flag = 1;
			down = up; 
		}
	}
	// cout << down << endl;
	if(n % down == 0)
		len = n / down;
	else {
		if(flag == 0)
			len = n / down - 1;
		else
			len = n / down;
	}
	for(int i = 1; i <= len; ++i) {
		for(int j = 0; j < down; ++j) {
			// cout << (i - 1) * len + 1 + j << "dd" << n - i * down + 1 + j << endl;;
			a[(i - 1) * down + 1 + j] = n - i * down + 1 + j; 
		}
	}
	if(n % down != 0) {
		for(int i = 1; i + len * down <= n; ++i) {
			a[i + len * down] = i;
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}
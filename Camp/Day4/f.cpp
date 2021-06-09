#include <bits/stdc++.h>
using namespace std;

int main() {
	bool flag = 1;
	int n, m, a, b, c, d;
	cin >> n >> m >> a >> b >> c >> d;
	if(n > m) {
		swap(n, m);
		swap(a, b);
		swap(c, d);
	}
	if((a + b + c + d) % 2 == 0) 
		flag = 0;
	else if(n >= 3 && m >= 4)
		flag = 1;
	else if(n == 3) {
		if((a == 2) && (b == 2))
			flag = 0;
		if((c == 2) && (d == 2))
			flag = 0;
	}
	else if(n == 2) {
		if(a == c)
			flag = ((d - b) % 4 == 0);
		else 
			flag = (((d - b) % 4 + 4) % 4 == 2);
	}
	else
		flag = 0;
	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
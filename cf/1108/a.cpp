#include <bits/stdc++.h>
using namespace std;

int main() {	
	int T, a, b, c, d;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c >> d;
		if(a == c) 
			c++;
		cout << a << " " << c << endl;
	}
	return 0;
}
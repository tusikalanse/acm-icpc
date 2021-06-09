#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(c == 0){
		if(a == b)
			puts("YES");
		else
			puts("NO");
	}
	else {
		int d = (b-a) / c;
		if(d < 0)
			puts("NO");
		else {
			if(a + c*d != b)
				puts("NO");
			else
				puts("YES");
		}
	}

	return 0;
}nn
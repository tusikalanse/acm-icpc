#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, flag = 1, mm, a, b;
	cin >> n;
	n--;
	cin >> a >> b;
	mm = max(a, b);
	while(n--) {
		cin >> a >> b;
		if(max(a, b) <= mm)
			mm = max(a, b);
		else if(min(a, b) <= mm)
			mm = min(a, b);
		else
			flag = 0;
	}
	puts(flag ? "YES" : "NO");

	return 0;
}
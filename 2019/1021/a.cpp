#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c, d;
	cin >> n;
	while (n--) {
		int cnt = 0;
		cin >> a >> b >> c >> d;
		cnt = !!a + !!b + !!c + !!d;
		if (cnt == 0)
			cout << "Typically Otaku" << endl;
		else if (cnt == 1)
			cout << "Eye-opener" << endl;
		else if (cnt == 2)
			cout << "Young Traveller" << endl;
		else if (cnt == 3)
			cout << "Excellent Traveller" << endl;
		else if (cnt == 4)
			cout << "Contemporary Xu Xiake" << endl;
	}
	return 0;
}
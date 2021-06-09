#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a = {1, 3, 435, 45323, 5};
	cout << accumulate(a.begin(), a.end(), 0) << endl;
	cout << accumulate(next(a.begin()), a.end(), \
		to_string(*a.begin()), [](string a, int b) {return a + "-" + to_string(b);}) << endl;



	return 0;
}
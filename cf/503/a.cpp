#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int n, h, a, b, k;
int ta, fa, tb, fb;

int main() {
	cin >> n >> h >> a >> b >> k;
	while(k--) {
		cin >> ta >> fa >> tb >> fb;
		if(ta == tb) {
			cout << abs(fa - fb) << endl;
		}
		else if(min(fa, fb) > b) {
			cout << fa - b + fb - b + abs(ta - tb) << endl;
		}
		else if(max(fa, fb) < a) {
			cout << a - fa + a - fb + abs(ta - tb) << endl;
		}
		else {
			cout << abs(fa - fb) + abs(ta - tb) << endl;
		}
	}
	return 0;
}
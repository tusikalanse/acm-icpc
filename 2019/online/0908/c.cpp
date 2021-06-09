#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, q, l, r, le, ri;

vector<int> c0, c1, c2, c8, c9;
char s[N];


int gao(int l, int r) {
	if(r - l < 3) return -1;
	auto pos = upper_bound(c2.begin(), c2.end(), r);
	if(pos == c2.begin()) return -1;
	r = *--pos;
	pos = upper_bound(c0.begin(), c0.end(), r);
	if(pos == c0.begin()) return -1;
	r = *--pos;
	pos = upper_bound(c1.begin(), c1.end(), r);
	if(pos == c1.begin()) return -1;
	r = *--pos;
	pos = lower_bound(c9.begin(), c9.end(), l);
	if(pos == c9.end() || *pos > r) return -1;
	l = *pos;
	pos = upper_bound(c1.begin(), c1.end(), l);
	l = *pos;

}

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '0') c0.push_back(i);
		if(s[i] == '1') c1.push_back(i);
		if(s[i] == '2') c2.push_back(i);
		if(s[i] == '8') c8.push_back(i);
		if(s[i] == '9') c9.push_back(i);
	}
	while(q--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", gao(l, r));
	}
	return 0;
}
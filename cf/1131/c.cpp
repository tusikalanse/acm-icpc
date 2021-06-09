#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int a[N], n, l, r;
int b[N];

int main() {
	scanf("%d", &n);
	multiset<int> s;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s.insert(-a[i]);
	}
	l = 2, r = n;
	b[n + 1] = b[1] = *s.begin();
	s.erase(s.find(b[1]));
	while(!s.empty()) {
		b[l] = *s.lower_bound(b[l - 1]);
		s.erase(s.find(b[l++]));
		if(s.empty())
			break;
		b[r] = *s.lower_bound(b[r + 1]);
		s.erase(s.find(b[r--]));
	}
	for(int i = 1; i <= n; ++i) 
		printf("%d%c", -b[i], " \n"[i == n]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 10;
char s[N], t[N];
int n, p[N], m;
vector<int> v[26];
long long ans;

void Manacher() {
	t[0] = '$';
	t[1] = '#';
	m = 2;
	for(int i = 0; i < n; ++i) {
		t[m++] = s[i];
		t[m++] = '#';
	}
	int mx = 0, id = 0, reslen = 0, resid = 0;
	for(int i = 0; i < m; ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while(t[i + p[i]] == t[i - p[i]])
			++p[i];
		if(mx < i + p[i]) {
			mx = i + p[i];
			id = i;
		}
		if(reslen < p[i]) {
			reslen = p[i];
			resid = i;
		}
	}
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i)
		v[s[i] - 'a'].push_back(i);
	Manacher();
	for(int i = 2; i < m - 1; ++i) {
		int md = (i - 1) / 2, r = (i + p[i] - 1 - 2) / 2;
		if(i % 2 == 1 && p[i] == 1) continue;
		for(int j = 0; j < 26; ++j) {
			auto pos = lower_bound(v[j].begin(), v[j].end(), md); 
			if(pos != v[j].end() && *pos <= r) {
				ans += r - *pos + 1;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
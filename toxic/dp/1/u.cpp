#include <bits/stdc++.h>
using namespace std;

long long ff[50];
int mx = 0;
stack<int> foo;
long long f(int k) {
	if(~ff[k]) 
		return ff[k];
	if(k == 0)
		return ff[k] = 0;
	return ff[k] = (1LL << (k - 1)) + 2 * f(k - 1);
}

long long g() {
	int tmp;
	long long ret = 0;
	while(!foo.empty()) {
		tmp = foo.top();
		foo.pop();
		ret += (1LL << mx);
		mx = tmp;
	}
	return ret;
}

int main() {
	memset(ff, -1, sizeof(ff));
	long long s;
	cin >> s;
	long long ans = 0;
	while((1LL << mx) <= s) mx++;
	mx--;
	for(int i = 0; i < mx; ++i) {
		if((1LL << i) & s) {
			ans += f(i);
			foo.push(i);
		}
	}
	ans += f(mx);
	ans += g();
	cout << ans << endl;
	return 0;
}
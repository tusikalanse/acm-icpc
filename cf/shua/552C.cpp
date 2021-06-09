#include <bits/stdc++.h>
using namespace std;

int w, m;
int a[100], cnt;

int main() {
	cin >> w >> m;
	if(w == 2) {
		cout << "YES" << endl;
	}
	else {
		while(m) {
			a[cnt++] = m % w;
			m /= w;
		}
		bool flag = 1;
		for(int i = 0; i < cnt; ++i) {
			if(a[i] == 0 || a[i] == 1) continue;
			if(a[i] == w || a[i] + 1 == w) a[i] = 0, a[i + 1] += 1;
			else flag = 0;
		}
		if(a[cnt] != 0 && a[cnt] != 1) flag = 0;
		if(flag) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
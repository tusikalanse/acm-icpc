#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e12 + 9;

long long f[510], k;
int T, n;
char s1[] = "COFFEE", s2[] = "CHICKEN";

void get(int x, long long num) {
	if(x == 1) cout << s1[num - 1];
	if(x == 2) cout << s2[num - 1];
	if(x <= 2) return;
	if(f[x - 2] >= num) get(x - 2, num);
	else get(x - 1, num - f[x - 2]);
}

int main() {
	f[1] = 6, f[2] = 7;
	for(int i = 3; i <= 500; ++i) 
		f[i] = min(MAX, f[i - 1] + f[i - 2]);
	cin >> T;
	while(T--) {
		cin >> n >> k;
		for(long long i = k; i < k + 10 && i <= f[n]; ++i)
			get(n, i);
		cout << endl;
	}
	return 0;
}
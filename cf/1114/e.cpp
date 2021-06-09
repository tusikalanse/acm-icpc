#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int vis[N], n, x, mx, c[33], g;

int main() {
	srand(time(NULL));
	cin >> n;
	for(int i = 29; ~i; --i) {
		if((mx ^ (1 << i)) > 1000000000) continue;
		cout << "> " << (mx ^ (1 << i)) << endl;
		cin >> x;
		if(x == 1)
			mx ^= 1 << i;
	}
	for(int i = 1; i <= min(n, 30); ++i) {
		x = (rand() ^ (rand() << 16)) % n + 1;
		while(vis[x])
			x = (rand() ^ (rand() << 16)) % n + 1;
		vis[x] = 1;
		cout << "? " << x << endl;
		cin >> c[i];
	}
	mx++;
	sort(c + 1, c + 1 + min(n, 30));
	for(int i = 1; i < min(n, 30); ++i) {
		g = __gcd(g, c[i + 1] - c[i]);
	}
	cout << "! " << (mx - (n - 1) * g) << " " << g << endl;
	return 0;
}
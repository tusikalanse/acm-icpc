#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 3;

int inv[1000004];

int main() {
	inv[1] = 1;
	for(int i = 2; i < 300; ++i) {
		inv[i] = ((mod - (mod / i)) * inv[mod % i] % mod + mod) % mod;
	}


	return 0;
}
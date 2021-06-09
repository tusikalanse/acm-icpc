#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int euler[MAXN];

void init() {
	for(int i = 1; i < MAXN; ++i)
		euler[i] = i;
	for(int i = 2; i < MAXN; ++i) {
		if(euler[i] == i) {
			for(int j = i; j < MAXN; j += i)
				euler[j] = euler[j] / i * (i - 1);
		}
	}
}

int main() {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}



int main() {


	return 0;
}

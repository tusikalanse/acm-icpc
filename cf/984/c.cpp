#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}



int main() {
	int n;
	long long p, q, b, md, mmp;
	scanf("%d", &n);
	while(n--) {
		scanf("%lld%lld%lld", &p, &q, &b);
		md = gcd(p, q);
		p /= md;
		q /= md;
		while((mmp = gcd(q, b)) != 1) {
			while(q % mmp == 0)
				q /= mmp; 
		}
		if(q == 1) 
			puts("Finite");
		else
			puts("Infinite");
	}
	return 0;
}
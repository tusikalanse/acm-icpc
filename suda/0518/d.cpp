#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	long long N;
	while(~scanf("%lld", &N)) {
		long long n = 1, n1 = 1, i = 1;
		while(true) {
			if(n == 1 && n1 == 0) 
				break;
			n = (n + n1) % N;
			n1 = (n + n1) % N;
			i++;
		}
		printf("%lld\n", i);
	}
	return 0;
}

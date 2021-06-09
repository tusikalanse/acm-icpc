#include <bits/stdc++.h>
using namespace std;
const int N = 150010;
int a[N], b[N], n;
vector<int> v;

void fac(int a) {
	for(int i = 2; i * i <= a; ++i) {
		if(a % i == 0) 
			v.push_back(i);
		while(a % i == 0)
			a /= i;
	}
	if(a != 1)
		v.push_back(a);
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)  
		scanf("%d%d", &a[i], &b[i]);
	if(n == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	fac(a[1]); fac(b[1]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 0; i < v.size(); ++i) {
		bool flag = 1;
		for(int j = 2; j <= n; ++j) {
			if(a[j] % v[i] != 0 && b[j] % v[i] != 0) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			printf("%d\n", v[i]);
			return 0;
		}
	}
	puts("-1");

	return 0;
}
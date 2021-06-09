#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, ans = 0;
	scanf("%d %d", &a, &b);
	int c = (a + b) >> 1;
	if(a > b) a ^= b ^= a ^= b;
	ans += (c - a)*(c - a + 1)/2;
	ans += (b - c)*(b - c + 1)/2;
	printf("%d\n", ans);
	return 0;
}
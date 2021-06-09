#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans = 0;
	int t;
	scanf("%d", &t);
	int a, b, c;
	for(a = 1; a<=t; a++)
		for(b = a; b<=t; b++){
			c = a^b;
			//printf("%d %d %d\n", a, b, c);
			if( c>=b && (a+b) > c && c<=t)
				ans++;
		}
		printf("%d\n", ans);
	return 0;
}
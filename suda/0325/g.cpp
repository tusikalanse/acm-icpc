#include <bits/stdc++.h>
using namespace std;

char a[200005], b[200005];

int main() {
	long long ans = 0, b0 = 0, b1 = 0;
	scanf("%s %s", a, b);
	int l = strlen(a), ll = strlen(b);
	for(int i = 0; i + l <= ll; i++) {
		if(b[i] == '0')
			b0++;
		else 
			b1++;
	}
	if(a[0] == '0')
		ans += b1;
	else 
		ans += b0;
	for(int i = 1; i < l; i++) {
		if(b[ll-l+i] == '0')
			b0++;
		else 
			b1++;
		if(b[i-1] == '0')
			b0--;
		else
			b1--;
		if(a[i] == '0')
			ans += b1;
		else 
			ans += b0;
	}
	printf("%lld\n", ans);
	return 0;
}
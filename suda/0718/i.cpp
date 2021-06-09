#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int ans[50], len, la, lb;
char a[50], b[50];


int main() {
	while(~scanf("%s%s", a, b)) {
		la = strlen(a);
		lb = strlen(b);
		len = max(la, lb);
		for(int i = 0; i < la; ++i)
			ans[i] += a[la - 1 - i] - '0';
		for(int i = 0; i < lb; ++i)
			ans[i] += b[lb - 1 - i] - '0';
		for(int i = len - 1; i >= 0; i--)
			printf("%d", ans[i]);
		puts("");
	}
	return 0;
}
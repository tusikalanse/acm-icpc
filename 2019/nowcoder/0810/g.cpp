#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

char s[N], stk[N];
int top, n, ans;

int main() {
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i) {
		stk[++top] = s[i];
		if(top >= 3 && stk[top] == stk[top - 1] && stk[top - 1] == stk[top - 2]) {
			ans++;
			top -= 3;
		}
	}
	printf("%d\n", ans);
	return 0;
}
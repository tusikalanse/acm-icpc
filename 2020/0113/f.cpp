#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

char s[N];

bool judge() {
	int n = strlen(s);
	stack<char> stk;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			stk.push('(');
		else {
			if (stk.empty())
				return false;
			stk.pop();
		}
	}
	return stk.empty();
}

int main() {
	scanf("%s", s);
	if (judge())
		puts("1");
	else
		puts("0");
	return 0;
}
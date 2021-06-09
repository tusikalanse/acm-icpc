#include <bits/stdc++.h>
using namespace std;
using LL = long long;


char s[510];
int T, n;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		n = strlen(s);
		bool zero = false;
		for(int i = 0; i < n; ++i) {
			if(s[i] == '?') {
				if(i != 0 && s[i - 1] == '0' && zero)
					s[i] = '+';
				else 
					s[i] = '9';
				zero = false;
			}
			else if(s[i] == '0' && (i == 0 || !isdigit(s[i - 1])))
				zero = true;
			else 
				zero = false;
		}
		bool flag = true;
		zero = false;
		if(s[0] == '+' || s[0] == '*')
			flag = false;
		else if(s[n - 1] == '+' || s[n - 1] == '*')
			flag = false;
		else
			for(int i = 0; i < n; ++i) {
				if(s[i] == '0' && (i == 0 || !isdigit(s[i - 1]))) {
					zero = true;
					continue;
				}
				if(i == 0)
					continue;
				if(isdigit(s[i])) {
					if(s[i - 1] == '0' && zero) {
						flag = false;
						break;
					}
					zero = false;
				}
				else {
					zero = false;
						if(s[i - 1] == '*' || s[i - 1] == '+') {
						flag = false;
						break;
					}
				}
			}
		if(flag) 
			printf("%s\n", s);
		else
			puts("IMPOSSIBLE");
	}
	return 0;
}
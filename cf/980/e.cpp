#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1 = 0, n2 = 0;
	char ch;
	while(~scanf("%c", &ch) && ch != '\n') {
		if(ch == '-')
			n1++;
		else if(ch == 'o')
			n2++;
	}
	if(n2 == 0 || n1 == 0)
		puts("YES");
	else if(n1 % n2 == 0)
		puts("YES");
	else 
		puts("NO");
	return 0;
}


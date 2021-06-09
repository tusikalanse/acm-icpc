#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[110];
int main() {
	scanf("%d%d%s", &n, &m, s);
	int cnt = 0;
	for(int i = 0; i < n; ++i) 
		cnt += s[i] == '1';
	printf("%d\n", cnt * m);
	return 0;
}
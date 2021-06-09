#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
char s[N];
int n, i, j, cnt;
vector<int> ans;
vector<int> a, b, c;
int main() {
	scanf("%s", s);
	n = strlen(s);
	if(n <= 3) {
		printf("%c\n", s[0]);
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'a')
			a.push_back(i);
		if(s[i] == 'b')
			b.push_back(i);
		if(s[i] == 'c')
			c.push_back(i);
	}
	i = 0, j = n - 1;
	if(s[i] != s[j]) {
		if(s[i + 1] == s[j])
			i++;
		else if(s[i] == s[j - 1])
			j--;
		else
			i++, j--;
	}
	ans.push_back(i);
	while(2 * ans.size() < n / 2) {
		i++, j--;
		if(s[i] != s[j]) {
			if(s[i + 1] == s[j])
				i++;
			else if(s[i] == s[j - 1])
				j--;
			else
				i++, j--;
		}
		if(i >= j)
			break;
		ans.push_back(i);
	}
	for(int i = 0; i < ans.size(); ++i)
		putchar(s[ans[i]]);
	if(2 * ans.size() < n / 2)
		putchar(s[1 + ans[ans.size() - 1]]);
	for(int i = ans.size() - 1; ~i; --i)
		putchar(s[ans[i]]);
	printf("\n");
	return 0;
}
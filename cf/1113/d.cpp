#include <bits/stdc++.h>
using namespace std;

char s[5100], t[5100];

int cnt[26], num, n;


int main() {
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
		if(cnt[s[i] - 'a'] == 1)
			num++;
	}
	if(num == 1 || n % 2 == 1 && cnt[s[n / 2] - 'a'] == 1 && num == 2) {
		puts("Impossible");
		return 0;
	}
	for(int i = 1; i < n; ++i) {
		bool f = true;
		for(int j = 0; j < i; ++j) {
			t[j + n - i] = s[j];
		}
		for(int j = i; j < n; ++j) {
			t[j - i] = s[j];  
		}
		if(string(s) == string(t)) continue;
		for(int j = 0; j < n; ++j) {
			if(t[j] != t[n - 1 - j]) {
				f = false;
				break;
			}
		}
		if(f) {
			puts("1");
			return 0;
		}
	}
	puts("2");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int T, n, ans;
char ch[10], s[1000010];


int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %s", &n, ch);
		scanf("%s", s);
		ans = 0;
		bool fi = 0;
		for(int i = 0; i < n; ++i) {
			if(fi) ans += 2;
			else {
				int c = abs(ch[0] - s[i]);
				if(c != 0) {
					fi = 1;
					if(c >= 10)
						ans += 2;
					else 
						ans++; 
				}
			}
		}
		if(ans == 0) ans = 1;
		printf("%d\n", ans);
	}

	return 0;
}
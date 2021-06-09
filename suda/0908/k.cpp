#include <bits/stdc++.h>
using namespace std;

int ans[] = {2, 3, 5, 7, 11, 13, 17, 23, 31, 37, 53, 71, 73, 113, 131, 137, 173, 311, 317};
int main() {
	int T, n, cas = 0;
	char s[200];
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		printf("Case #%d: ", ++cas);
		if(strlen(s) > 3) 
			printf("317\n");
		else {
			n = stoi(s);
			if(n >= 317)
				printf("%d\n", 317);
			else
				for(int i = 0;;++i)
					if(ans[i] > n) {
						printf("%d\n", ans[i - 1]);
						break;
					}
		}
	}



	return 0;
}
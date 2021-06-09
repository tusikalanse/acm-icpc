#include <cstdio>
using namespace std;

int main(){
	int n, ans = 0;
	char s[20];
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		switch(s[0]){
			case 'T':
				ans += 4;
				break;
			case 'C':
				ans += 6;
				break;
			case 'O':
				ans += 8;
				break;
			case 'D':
				ans += 12;
				break;
			case 'I':
				ans += 20;
				break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
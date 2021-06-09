#include <cstdio>
using namespace std;

int main() {
	int T, n, b, a;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &b);
		int flag = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a);
			if((a + b) % 7 == 0) 
				flag = 1;
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}
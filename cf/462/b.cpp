#include <cstdio>
using namespace std;


int main(){
	int n;
	scanf("%d", &n);
	if(n > 36) printf("-1\n");
	else {
		if(n&1) printf("4");
		n >>= 1;
		while(n--) printf("8");
		puts("");
	}
	return 0;
}
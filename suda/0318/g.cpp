#include <cstdio>
using namespace std;


int main(){
	int t, n;
	scanf("%d", &t);
	for(int _ = 1; _<=t; _++){
		scanf("%d", &n);
		printf("Case #%d:\n", _);
		puts("*------------*");
		for(int i = 10; i>0; i--){
			if(!(10*i <= n))
				puts("|............|");
			else
				puts("|------------|");
		}
		puts("*------------*");
	}


	return 0;
}
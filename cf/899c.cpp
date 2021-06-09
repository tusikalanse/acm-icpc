#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
	int n;
	scanf("%d", &n);
	int t = n%4;
	switch (t){
		case 0:
			puts("0");
			printf("%d", n/2);
			for(int i = 1; i<n/2+1; i++)
				printf(" %d", i*2-(i&1));
			break;
		case 1:
			puts("1");
			printf("%d", n/2);
			for(int i = 0; i<n; i+=2)
				printf(" %d", i/4*8+(i%4?4:1));
			break;
		case 2:
			puts("1");
			printf("%d", n/2);
			for(int i = 1; i<n/2; i++)
				printf(" %d", i*2-(i&1));
			printf(" %d", n-1);
			break;
		case 3:
			puts("0");
			printf("%d", n/2);
			for(int i = 1; i<n/2; i++)
				printf(" %d", i*2-(i&1));
			printf(" %d", n);
			break;
		
		
		
		
	}
	
	return 0;
}

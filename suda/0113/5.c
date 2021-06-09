#include <stdio.h>

int main(){
	unsigned long long n, temp;
	int t, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d %llu", &m, &n);
		for (int i = m-1; i>=0; i--){ temp = n;
			for(int j = 0; j<i; j++) temp = temp/3;
			if (temp%3==0) printf("R");
			else if(temp%3==1) printf("G");
			else printf("B");}
		puts("");
	}
	return 0;
}

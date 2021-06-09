#include <stdio.h>

void bin(int t);
int main()
{
	int t;
	while(~scanf("%d", &t)) {bin(t); puts("");}
	return 0;
}

void bin(int t){
	if (t){
		bin(t/2);
		printf("%d", t%2);
	}
}

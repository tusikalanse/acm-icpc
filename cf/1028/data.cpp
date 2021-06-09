#include <bits/stdc++.h>
using namespace std;
#define r rand() % (100000000)

int main() {
	printf("0 0 1 1\n");
	printf("3 3 4 4\n");
	printf("7 7 8 8\n");
	srand(time(NULL));
	for(int i = 4; i <= 132674; ++i) {
		printf("%d %d %d %d\n", r, r, r, r);
	}
	return 0;
}
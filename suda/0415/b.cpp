#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s1[100000], s2[100000];

int main() {
	int T, n, x, y;
	scanf("%d", &T);
	while(T--) {
		int flag = 0, dif = 0;
		scanf("%d %d %d %s %s", &n, &x, &y, s1, s2);
		for(int i = 0; i < n; i++)
			dif += (s1[i] != s2[i]);
		flag |= (x + y > 2 * n - dif);
		flag |= (abs(x - y) > dif);
		puts(flag ? "Lying" : "Not lying");
	}
	return 0;
}
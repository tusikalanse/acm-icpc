#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Cow{
	int minspf, maxspf;
	bool operator < (const Cow &rhs) const {
		return minspf > rhs.minspf;
	}
}cows[3000];

int bottle[1010] = {0};

int main() {
	int c, l, spf, cover;
	scanf("%d %d", &c, &l);
	for(int i = 0; i < c; i++) {
		scanf("%d %d", &cows[i].minspf, &cows[i].maxspf);
	}
	while(l--) {
		scanf("%d %d", &spf, &cover);
		bottle[spf] += cover;
	}
	int ans = 0;
	sort(cows, cows + c);
	for(int i = 0; i < c; i++) {
		for(int j = cows[i].maxspf; j >= cows[i].minspf; --j) {
			if(bottle[j] != 0) {
				--bottle[j];
				++ans;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0; 
}
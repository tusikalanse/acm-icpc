#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
	char s[110];
}lst[10010];

char tmp[110];

int get_min(char *s) {
	int i = 0, j = 1, k = 0, len = strlen(s);
	while(i < len && j < len && k < len) {
		int t = s[(i+k) % len] - s[(j+k) % len];
		if(t == 0)
			++k;
		else {
			if(t > 0)
				i += k + 1;
			else
				j += k + 1;
			if(i == j)
				++j;
			k = 0;
		}
	}
	return min(i, j);
}

bool cmp(const node &i, const node &j) {
	if(strcmp(i.s, j.s) > 0)
		return 1;
	return 0;
}


int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; ++i) {
			scanf("%s", lst[i].s);
			int len = strlen(lst[i].s), cnt = get_min(lst[i].s);
			strcpy(tmp, &lst[i].s[cnt]);
			lst[i].s[cnt] = '\0';
			strcpy(&tmp[len-cnt], lst[i].s);
			strcpy(lst[i].s, tmp);
		}
		sort(lst + 1, lst + 1 + n, cmp);
		int sum = 1;
		for(int i = 2; i <= n; ++i) {
			sum += (strcmp(lst[i-1].s, lst[i].s) != 0);
		}
		printf("%d\n", sum);
	}


	return 0;
}
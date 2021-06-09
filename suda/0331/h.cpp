#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char s[100005];

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int ped = 0;
		scanf("%s", s);
		int len = strlen(s);
		vector<int> first;
		for(int i = 1; i < len; i++) 
			if(s[i] == s[0])
				first.push_back(i);
		for(int i = 0; i < first.size(); i++) {
			int d = first[i];
			int flag = 0, j;
			for(j = 1; (j+1) * d <= len; j++) {
				for(int k = 0; k < d; k++) 
					if(s[k] != s[j*d + k]) {
						flag = 1;
						break;
					}
				if(flag)
					break;
			}
			for(int k = j*d; k < len; k++)
				if(s[k%d] != s[k]) {
					flag = 1;
					break;
				}
			if(flag)
				continue;
			else {
				if(len%d == 0) puts("0");
				else
					printf("%d\n", d - len%d);
				ped = 1;
				break;
			}
		}
		if(ped == 0)
			printf("%d\n", len);
	}


	return 0;
}
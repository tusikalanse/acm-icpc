#include <bits/stdc++.h>
using namespace std;

map<int, int> num;

struct Movie {
	int pos, audio, subtitle;
}mv[200005];



int main() {
	int n, t, m;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &t);
		num[t]++;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &mv[i].audio);
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", &mv[i].subtitle);
	}
	int id = 0;
	for(int i = 1; i < m; i++) {
		if(num[mv[id].audio] < num[mv[i].audio])
			id = i;
		else if(num[mv[id].audio] == num[mv[i].audio] && num[mv[id].subtitle] < num[mv[i].subtitle])
			id = i;
	}
	printf("%d\n", id + 1);
	return 0;
}
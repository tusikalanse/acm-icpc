#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int x, y;
}lst[55];

int cross(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

int dis(Point c, Point a, Point b) {
	return cross(a.x - c.x, a.y - c.y, b.x - c.x, b.y - c.y);
}

bool cmp(Point i, Point j) {
	if(dis(lst[0], i, j) == 0) {
		return i.x < j.x;
	}
	return dis(lst[0], i, j) > 0;
}


int main() {
	int cnt = 0;
	while(~scanf("%d %d", &lst[cnt].x, &lst[cnt].y))
		++cnt;
	stable_sort(lst + 1, lst + cnt, cmp);
	for(int i = 0; i < cnt; ++i) 
		printf("(%d,%d)\n", lst[i].x, lst[i].y);
	return 0;
}
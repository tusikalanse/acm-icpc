#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[1005];
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Unite(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}


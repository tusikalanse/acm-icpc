#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Cube
{
	int x, y, z;
	Cube() {}
	Cube(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	bool operator < (const Cube &rhs){
		return (x == rhs.x)? (y < rhs.y): (x < rhs.x);
	}
}cube[200];

int dp[200];

int main(){
	int n, xi, yi, zi, cas = 0;
	while(~scanf("%d", &n) && n){
		int cnt = 0, ans = 0;
		cube[cnt++] = Cube(-1, -1, 0);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d", &xi, &yi, &zi);
			cube[cnt++] = Cube(xi, yi, zi);
			cube[cnt++] = Cube(xi, zi, yi);
			cube[cnt++] = Cube(yi, xi, zi);
			cube[cnt++] = Cube(yi, zi, xi);
			cube[cnt++] = Cube(zi, xi, yi);
			cube[cnt++] = Cube(zi, yi, xi);
		}
		sort(cube, cube + cnt);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i < cnt; i++){
			for(int j = i - 1; j >= 0; j--){
				if(cube[i].x > cube[j].x && cube[i].y > cube[j].y){
					dp[i] = max(dp[i], dp[j] + cube[i].z);
					ans = max(ans, dp[i]);
				}
			}
		}
		printf("Case %d: maximum height = %d\n", ++cas, ans);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1005;
struct g
{
	int power, number;
	double ans;
	int p[MAXN];
	void init(){
		for(int i = 0; i<MAXN; i++) p[i] = 0;
		power = number = 0;
		ans = 0;	
	}
}gun[MAXN];
double parts[MAXN];
int main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	int n, m, id;
	double temp, ans, ratio;
	while(~scanf("%d%d", &n, &m)){
		ans = 0;
		memset(parts, 0.0, sizeof(parts));
		for(int i = 0; i<n; i++) gun[i].init();
		for(int i = 0; i<n; i++) {
			scanf("%d %d", &gun[i].power, &gun[i].number);
			gun[i].ans = gun[i].power;
			for(int j = 0; j<gun[i].number; j++)
				scanf("%d", &gun[i].p[j]);
		}
		for(int i = 0; i<m; i++){
			scanf("%d %lf", &id, &temp);
			parts[id] = max(parts[id], temp);
		}
		for(int i = 0; i<n; i++){
			ratio = 0;
			for(int j = 0; j<gun[i].number; j++){
				ratio += parts[gun[i].p[j]];
			}
			gun[i].ans *= (1+ratio);
			ans = max(ans, gun[i].ans);
			//printf("gun[%d] = %lf\n", i, gun[i].ans);
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}
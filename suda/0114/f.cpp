#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int father[1002];
int coor[1002][3];
int Find(int x){
	int i = x; 
	while(father[i] != i) i = father[i];
	father[x] = i;
	return i;
}


void unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy) father[fx] = fy;
}


int main(){
	int n, m, a, b, c;
	char com[5];
	memset(coor, 0, sizeof(coor));
	scanf("%d %d", &n, &m);
		for(int i = 1; i<=n; i++) father[i] = i;
		for(int i = 1; i<=n; i++) scanf("%d %d", &coor[i][0], &coor[i][1]);
		while (~scanf("%s", com)){
			if(com[0] == 'O'){
				scanf("%d", &c);
				coor[c][2] = 1;
				for(int i = 1; i<=n; i++)
					if (coor[i][2] && sqrt((coor[i][0]-coor[c][0])*(coor[i][0]-coor[c][0])+(coor[i][1]-coor[c][1])*(coor[i][1]-coor[c][1]))<= m && father[c]!=father[i])
						unite(i, c);
				}
			else{
				scanf("%d %d", &a, &b);
				if (Find(a) == Find(b))
					printf("SUCCESS\n");
				else
					printf("FAIL\n");
			}
			
		}
		
	return 0;
}

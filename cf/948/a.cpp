#include <bits/stdc++.h>
using namespace std;

int R, C;
int mp[505][505];
char ch;
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

bool valid(int x, int y){
	if(x <= 0) return false;
	if(x > R)  return false;
	if(y <= 0) return false;
	if(y > C)  return false;
	return true;
}

int main(){
	memset(mp, 0, sizeof(mp));
	scanf("%d %d", &R, &C);
	getchar();
	for(int i = 1; i<=R; i++){
		for(int j = 1; j<=C; j++){
			ch = getchar();
			if(ch == 'W')
				mp[i][j] = 2;
			else if(ch == 'S')
				mp[i][j] = 1;
		}
		getchar();
	}
	int flag = 1;
	for(int i = 1; i<=R; ++i){
		for(int j = 1; j<=C; ++j){
			if(mp[i][j] == 2){
				for(int k = 0; k<4; k++){
					int fx = i + dir[k][0], fy = j + dir[k][1];
					if(valid(fx, fy) && mp[fx][fy] == 1){
						flag = 0;
						goto out;
					}
				}
			}
		}
	}
	out:;
	if(flag){
		puts("Yes");
		for(int i = 1; i<=R; i++){
			for(int j = 1; j<=C; j++){
				if(mp[i][j] == 0)
					putchar('D');
				else if(mp[i][j] == 1)
					putchar('S');
				else putchar('W');
			}
			puts("");
		}
	}
	else
		puts("No");


	return 0;
}
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};

struct Point{
    int x, y, s;
    int d[4];
}mp[55][55], temp;

int vis[55][55], xin, xout, yin, yout;

int main() {
    int t, n, mij;
    scanf("%d", &t);
    while(t--) {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        int lim = 10000;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &mij);
                mp[i][j].x = i;
                mp[i][j].y = j;
                mp[i][j].d[0] = mij & 2;
                mp[i][j].d[1] = mij & 8;
                mp[i][j].d[2] = mij & 4;
                mp[i][j].d[3] = mij & 1;
                mp[i][j].s = 0;
                if(mij > 32){
                    xout = i;
                    yout = j;
                }
                else if(mij > 16 && mij < 32){
                    xin = i;
                    yin = j;
                }
            }
        }
        queue<Point> bfs;
        vis[xin][yin] = 1;
        bfs.push(mp[xin][yin]);
        while(!bfs.empty()) {
            temp = bfs.front();
            bfs.pop();
            for(int i = 0; i < 4; i++) {
                int fx = temp.x + dir[i][0], fy = temp.y + dir[i][1];
                if(temp.d[i]) { 
                    if(fx == 0 || fx == n+1 || fy == 0 || fy == n+1 )
                        lim = min(lim, temp.s+1);
                    else{
                        if(mp[fx][fy].d[i^1]) {
                            if(!vis[fx][fy]){ 
                                vis[fx][fy] = 1;
                                mp[fx][fy].s = temp.s + 1;
                                bfs.push(mp[fx][fy]);
                            }
                        }
                        else
                            lim = min(lim, temp.s+1);
                     }                      
                }
            }
        }
        int ans = 0;
        if(mp[xout][yout].s != 0)
        lim = min(lim, mp[xout][yout].s);
        vis[xin][yin] = vis[xout][yout] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                if(vis[i][j] && mp[i][j].s <= lim)
                    ans++;
        }
        printf("%d\n", ans);
    } 
    return 0;
}

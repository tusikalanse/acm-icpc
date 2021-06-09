#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> black, white;
bool cmp(pii a, pii b) {
    return a.first > b.first;
}
pii c[55];

int ans[6][6];

int main() {
    int T, n, m, k, f, cas = 0;
    scanf("%d", &T);
    while(T--) {
        black.clear();
        white.clear();
        printf("Case #%d:\n", ++cas);
        scanf("%d %d %d", &n, &m, &k);
        f = 0;
        if(n < m) {
            f = 1;
            n ^= m ^= n ^= m;
        }
        int mmax = 0, id;
        for(int i = 1; i <= k; i++) {
            scanf("%d", &c[i].first);
            c[i].second = i;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if((i+j) % 2 == 0)
                    black.push_back(make_pair(i, j));
                else
                    white.push_back(make_pair(i, j));
            }
        }
        sort(c + 1, c + 1 + k, cmp);
        if(c[1].first > (n*m+1)/2) {
            puts("NO");
            continue;
        }
        puts("YES");
        int black_front = 0, white_front = 0, black_back = black.size() - 1, white_back = white.size() - 1;
        for(int i = 1; i <= k; i++) {
            if(i % 2 == 1) {
                while(c[i].first--) {
                    //printf("%d ", c[i].second);
                    if(black_front != black.size()){
                        ans[black[black_front].first][black[black_front].second] = c[i].second;
                        black_front++;
                    }
                    else{
                        ans[white[white_front].first][white[white_front].second] = c[i].second;
                        white_front++;
                    }
                }
            }
            else {
                while(c[i].first--) {
                                        //printf("%d ", c[i].second);
                    if(white_back != -1) {
                        ans[white[white_back].first][white[white_back].second] = c[i].second;
                        white_back--;
                    }
                    else {
                        ans[black[black_back].first][black[black_back].second] = c[i].second;
                        black_back--;
                    }
                }
            }
        }
        if(f) {
            n ^= m ^= n ^= m;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    printf("%d%c", ans[j][i], (j == m) ? '\n' : ' ');
                }
            }
        }
        else {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    printf("%d%c", ans[i][j], (j == m) ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}
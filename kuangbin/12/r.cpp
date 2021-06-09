#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005];
struct Interval {
    int starting_hour, ending_hour, effiency;
    bool operator < (const Interval &rhs) const {
        if(starting_hour == rhs.starting_hour)
            return ending_hour < rhs.ending_hour;
        return starting_hour < rhs.starting_hour;
    }
}t[1005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int mmax = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &t[i].starting_hour, &t[i].ending_hour, &t[i].effiency);
        t[i].ending_hour += r;
    }
    sort(t, t + m);
    mmax = dp[0] = t[0].effiency;
    for(int i = 1; i < m; i++) {
        dp[i] = t[i].effiency;
        for(int j = 0; j < i; j++) {
            if(t[j].ending_hour <= t[i].starting_hour)
                dp[i] = max(dp[i], dp[j] + t[i].effiency);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        }
        mmax = max(dp[i], mmax);
    }
    printf("%d\n", mmax);
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[15];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= 12; i++) {
        for(int j = 1; j <= i; j++) 
            dp[i] = min(dp[i], 2*dp[i-j] + (1 << j) - 1);
    }
    for(int i = 1; i <= 12; i++)
        printf("%d\n", dp[i]);
    return 0;
}

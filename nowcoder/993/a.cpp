#include <bits/stdc++.h>
using namespace std;

int c[100010], n, k, p;
queue<int> que;

int main() {
    scanf("%d%d%d", &n, &k, &p);
    for(int i = 1; i <= k; ++i) {
        que.push(i);
    }
    for(int i = 1; i <= k; ++i) {
        if(i % n == 0) {
            c[i / n] = que.front();
        }
        que.pop();
        for(int i = 0; i < p; ++i) {
            que.push(que.front());
            que.pop();
        }
    }
    sort(c + 1, c + k / n + 1);
    for(int i = 1; i <= k / n; ++i) {
        printf("%d\n", c[i]);
    }
    return 0;
}
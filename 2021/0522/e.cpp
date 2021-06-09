#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T, mx, my, n;
char s[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &mx, &my);
        scanf("%s", s);
        n = strlen(s);
        int dx = 0, dy = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                x--;
                dx++;
            }
            else if (s[i] == 'R') {
                x++;
                dx++;
            }
            else if (s[i] == 'U') {
                y++;
                dy++;
            }
            else if (s[i] == 'D') {
                y--;
                dy++;
            }
        }
        if ((x == mx && y == my) || (mx == 0 && my == 0)) {
            printf("Impossible\n");
        }
        else {
            if ((dx == 0 && mx == 0 && abs(y) > abs(my) && 1LL * y * my > 0) || (dy == 0 && my == 0 && abs(x) > abs(mx) && 1LL * x * mx > 0))
               printf("Impossible\n");
            else {
                if (y != my) {
                    if (mx != 0) {
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'U' || s[i] == 'D')
                                putchar(s[i]);
                        }
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'L' || s[i] == 'R')
                                putchar(s[i]);
                        }
                    }
                    else {
                        int first = 0;
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'L' || s[i] == 'R') {
                                if (first == 0) {
                                    putchar(s[i]);
                                    break;
                                }
                            }
                        }
                        if (my > (y + dy) / 2 || my < y) {
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'U')
                                    putchar(s[i]);
                            }
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'D')
                                    putchar(s[i]);
                            }
                        }
                        else {
                            assert(my > y || my < (dy - y) / 2);
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'D')
                                    putchar(s[i]);
                            }
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'U')
                                    putchar(s[i]);
                            }
                        }
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'L' || s[i] == 'R') {
                                if (first == 0) {
                                    first = 1;
                                    continue;
                                }
                                else 
                                    putchar(s[i]);
                            }
                        }
                    }
                }
                else {
                    assert(x != mx);
                    if (my != 0) {
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'L' || s[i] == 'R')
                                putchar(s[i]);
                        }
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'U' || s[i] == 'D')
                                putchar(s[i]);
                        }
                    }
                    else {
                        int first = 0;
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'U' || s[i] == 'D') {
                                if (first == 0) {
                                    putchar(s[i]);
                                    break;
                                }
                            }
                        }
                        if (mx > (x + dx) / 2 || mx < x) {
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'R')
                                    putchar(s[i]);
                            }
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'L')
                                    putchar(s[i]);
                            }
                        }
                        else {
                            assert(mx > x || mx < (dx - x) / 2);
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'L')
                                    putchar(s[i]);
                            }
                            for (int i = 0; i < n; ++i) {
                                if (s[i] == 'R')
                                    putchar(s[i]);
                            }
                        }
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == 'U' || s[i] == 'D') {
                                if (first == 0) {
                                    first = 1;
                                    continue;
                                }
                                else 
                                    putchar(s[i]);
                            }
                        }
                    }
                }
              putchar('\n');
            }
        }
    }
    return 0;
}
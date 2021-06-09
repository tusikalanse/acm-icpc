#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;

pair<int, int> lst[100006];

int main() {
    int t, v, front, rear, p, q;
    char com[7];
    scanf("%d", &t);
    while(t--) {
        front = rear = p = q = 0;
        scanf("%s", com);
        while(scanf("%s", com) && com[0] != 'E') {
            if(com[0] == 'C') {
                scanf("%*s %d", &v);
                while(front < rear && v > lst[rear-1].second)
                    rear--;
                lst[rear++] = make_pair(q, v);
                q++;
            }
            else if(com[0] == 'Q')
                if(front < rear)
                    printf("%d\n", lst[front].second);
                else 
                    puts("-1");
            else {
                if(p == lst[front].first)
                    front++;
                p++;
            }
        }
    }
    return 0;
}

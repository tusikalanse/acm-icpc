/*
 * @Author: tusikalanse
 * @Date: 2021-06-12 20:42:59
 * @LastEditTime: 2021-06-12 21:34:33
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/arc/122/c.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
LL n;
int k;

struct node {
    LL x, y, step;
    LL judge() const {
        if (step > 130) return -1000000000000000000;
        if (x > n) return -1000000000000000000;
        if (x == n) return 1000000000000000000;
        if (x + y > n) return -(n - x);
        return x + y;
    }
    bool operator<(const node &rhs) const {
        return judge() < rhs.judge();
    }
};

map<int, map<int, node>> pre;

vector<int> op;

void print(node u) {
    if (u.x == 0 && u.y == 0) return;
    print({pre[u.x][u.y].x, pre[u.x][u.y].y});
    int x = pre[u.x][u.y].x, y = pre[u.x][u.y].y;
    if (u.x == x + 1 && u.y == y)
        op.push_back(1);
    else if (u.x == x && u.y == y + 1)
        op.push_back(2);
    else if (u.x == x + y && u.y == y)
        op.push_back(3);
    else if (u.x == x && u.y == x + y)
        op.push_back(4);
    else {
        assert(false);
    }
}

int main() {
    cin >> n;
    priority_queue<node> pq;
    node ans;
    pq.push({0, 0});
    pre[0][0] = {0, 0};
    while (!pq.empty()) {
        node s = pq.top();
        pq.pop();
        if (s.x == n) {
            ans = s;
            break;
        }
        if (s.x > n && s.y >= n) continue;
        //cout << s.x << " " << s.y << " " << pq.size() << endl;
        node u = s;
        u.x++;
        u.step++;
        if (pre[u.x].find(u.y) == pre[u.x].end()) {
            pq.push(u);
            pre[u.x][u.y] = s;
        }
        u = s;
        u.y++;
        u.step++;
        if (pre[u.x].find(u.y) == pre[u.x].end()) {
            pq.push(u);
            pre[u.x][u.y] = s;
        }
        u = s;
        u.x += u.y;
        u.step++;
        if (pre[u.x].find(u.y) == pre[u.x].end()) {
            pq.push(u);
            pre[u.x][u.y] = s;
        }
        u = s;
        u.y += u.x;
        u.step++;
        if (pre[u.x].find(u.y) == pre[u.x].end()) {
            pq.push(u);
            pre[u.x][u.y] = s;
        }
    }
    print(ans);
    cout << op.size() << endl;
    for (int i : op)
        cout << i << endl;
    return 0;
}

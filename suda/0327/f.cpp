#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000006;

struct node{
    int l, r, mmax;
}Tree[MAXN << 2];

void pushup(int rt){
    Tree[rt].mmax = max(Tree[rt << 1].mmax, Tree[rt << 1 | 1].mmax);
}

void build(int rt, int l, int r){
    Tree[rt].l = l;
    Tree[rt].r = r;
    if(l == r){
        Tree[rt].mmax = 0;
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int pos, int val){
    if(Tree[rt].l == Tree[rt].r){
        Tree[rt].mmax = val;
        return;
    }
    int mid = Tree[rt].l + Tree[rt].r >> 1;
    if(mid >= pos)
        update(rt << 1, pos, val);
    else 
        update(rt << 1 | 1, pos, val);
    pushup(rt);
}

int query(int rt, int l, int r) {
    if(Tree[rt].l >= l && Tree[rt].r <= r){
        return Tree[rt].mmax;
    }
    int mid = Tree[rt].l + Tree[rt].r >> 1;
    int res = 0;
    if(mid >= l)
        res = query(rt << 1, l, r);
    if(mid < r)
        res = max(res, query(rt << 1 | 1, l, r));
    return res;
}

int main() {
    int t, m, n, v;
    char s[10], Name[10];
    int Front, rear;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        Front = rear = 1;
        build(1, 1, MAXN - 1);
        while(true) {
            scanf("%s", s);
            if(s[0] == 'E')
                break;
            else if(s[0] == 'C'){
                scanf("%s %d", Name, &v);
                update(1, rear, v);
                rear++;
            }
            else if(s[0] == 'G')
                Front++;
            else {
                if(Front == rear)
                    puts("-1");
                else 
                    printf("%d\n", query(1, Front, rear-1));
            }   
        }
    }
    return 0;
}

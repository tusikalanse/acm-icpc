#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1e6;
int fact[12] = {1, 1};

int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
char d[8] = "udrl";
int vis[MAXN];

struct node
{ 
	int x, y, g, h, Hash, f[3][3];
	bool operator < (const node &rhs) const{
		return h==rhs.h?g>rhs.g:h>rhs.h;
	}
};

struct path
{
	int pre;
	char ch;
}p[MAXN];

int get_h(node e){
	int ans = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++){
			if(e.f[i][j])
				ans += abs(i - (e.f[i][j] - 1)/3) + abs(j - (e.f[i][j] - 1)%3);
		}
	ans /= 2;
	return ans;
}


void print(int k){
	if(p[k].pre == -1)
		return;
	print(p[k].pre);
	putchar(p[k].ch);
	return;
}


int Cantor_expansion(node e){
	int k = 0, ans = 0, a[9];
	for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++)
			a[k++] = e.f[i][j];
	for(int i = 0; i<9; i++){
		k = 0;
		for(int j = i+1; j<9; j++){
			if(a[j] < a[i])
				k++;
		}
		ans += k*fact[8-i];
	}
	return ans;
}

void Astar(node e){
	memset(vis, 0, sizeof(vis));
	node a, b;
	int tar, nx, ny, k;
	for(int i = 0; i<9; i++)
		a.f[i/3][i%3] = (i+1)%9;
	e.Hash = Cantor_expansion(e);
	tar = Cantor_expansion(a);
	e.g = 0;
	e.h = get_h(e);
	vis[e.Hash] = 1;
	p[e.Hash].pre = -1;
	priority_queue<node> q;
	q.push(e);
	while(!q.empty()){
		b = q.top();
		q.pop();
		if(b.Hash == tar){
			print(b.Hash);
			puts("");
			return;
		}
		for (int i = 0; i < 4; ++i)
		{
			nx = b.x + dir[i][0];
			ny = b.y + dir[i][1];
			if(nx<0 || nx>=3 || ny<0 || ny >=3)
				continue;
			a = b;
			swap(a.f[nx][ny], a.f[b.x][b.y]);
			k = Cantor_expansion(a);
			if(vis[k])continue;
			vis[k] = 1;
			a.Hash = k;
			a.x = nx;
			a.y = ny;
			a.g++;
			a.h = get_h(a);
			p[k].pre = b.Hash;
			p[k].ch = d[i];
			q.push(a);
		}
	}
	return;
}


int main(int argc, char const *argv[])
{
	for(int i = 2; i<12; i++)
	fact[i] = i*fact[i-1];
	char lst[30];
	while(fgets(lst, 28, stdin)){
		int i,j,k,n;  
        node e;  
        n=strlen(lst);  
        for(i=0,j=0;i<n;i++)  
        {  
            if(lst[i]==' ')continue;  
            if(lst[i]=='x'){e.f[j/3][j%3]=0;e.x=j/3;e.y=j%3;}  
            else e.f[j/3][j%3]=lst[i]-'0';  
            j++;  
        }  
        //判断逆序数  
        for(i=0,k=0;i<9;i++)  
        {  
            if(e.f[i/3][i%3]==0)continue;  
            for(j=0;j<i;j++)  
            {  
                if(e.f[j/3][j%3]==0)continue;  
                if(e.f[j/3][j%3]>e.f[i/3][i%3])k++;  
            }  
        }  
        if(k&1)printf("unsolvable\n");  
        else Astar(e);  
	}
	return 0;
}
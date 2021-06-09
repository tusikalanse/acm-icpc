#include <bits/stdc++.h>
using namespace std;

struct node
{
	int ab, id;
	bool operator < (const node &rhs) const {
		return ab > rhs.ab;
	}
}ser[300010];


int vis[300010];

int n, A, B;
int main() {
	int f = 0, aaa, das;
	cin >> n >> A >> B;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &ser[i].ab);
		ser[i].id = i;
	}
	sort(ser + 1, ser + 1 + n);
	if(A < B) {
		swap(A, B);
		f = 1;
	}
	int i;
	for(i = 1; i < n; ++i) {
		if(ser[i].ab >= (A-1)/i + 1) 
			break;
	}
	if(i == n) {
		cout << "No" << endl;
		return 0;
	}
	int j = i;
	aaa = i;
	while(ser[j].ab >= (A-1)/i + 1) j++;
	j--;
	while(i--)
		vis[j--] = 1;
	vector<node> fb(1);
	for(int i = 1; i <= n; ++i) 
		if(!vis[i])
			fb.push_back(ser[i]);
	for(i = 1; i < fb.size(); ++i) {
		if(fb[i].ab >= (B-1)/i + 1) {
			das = i;
			break;
		}
	}
	if(i == fb.size()) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if(f) {
		printf("%d %d\n", das, aaa);
		for(int j = 1; j <= das; ++j)
			printf("%d ", fb[j].id);
		puts("");
		for(int i = 1; i <= n; ++i)
			if(vis[i])
				printf("%d ", ser[i].id);
		puts("");
	}
	else {
		printf("%d %d\n", aaa, das);
		for(int i = 1; i <= n; ++i)
			if(vis[i])
				printf("%d ", ser[i].id);
		puts("");
		for(int j = 1; j <= das; ++j)
			printf("%d ", fb[j].id);
		puts("");
	}
	return 0;
}
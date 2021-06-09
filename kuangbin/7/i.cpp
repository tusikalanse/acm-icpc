#include <cstdio>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x;
	char c[3];
	while(~scanf("%d %d", &n, &m)) {
		stack<int> s;
		set<int> st;
		st.insert(0);
		st.insert(n + 1);
		while(m--) {
			scanf("%s", c);
			if(c[0] == 'R') {
				st.erase(s.top());
				s.pop();
			}
			else {
				scanf("%d", &x);
				if(c[0] == 'D') {
					s.push(x);
					st.insert(x);
				}
				else {
					if(st.find(x) != st.end())
						puts("0");
					else {
						set<int>::iterator L = st.lower_bound(x);
						set<int>::iterator R = st.lower_bound(x);
						--L;
						printf("%d\n", *R - *L - 1);
					}
				}
			}
		}
	}
	return 0;
}
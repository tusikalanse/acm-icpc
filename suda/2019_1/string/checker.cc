#include <fstream>
using namespace std;

int main() {
	ifstream in("input");
	ifstream user("user_output");
	string s; int n;
	in >> n;
	user >> s;
	if (s.size() != n) return 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] != 'i' && s[i] != 'j') return 1;
		if (i >= 2 && s[i - 2] == s[i]) return 1;
	}
	return 0;
}
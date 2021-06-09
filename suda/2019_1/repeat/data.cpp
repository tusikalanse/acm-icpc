#include <bits/stdc++.h>
using namespace std;

void input(int id) {
	string in = to_string(id) + ".in";
	ofstream fin(in);
	int n = 1 + rand() % 100, m = 1 + rand() % 1000;
	string s[1010];
	s[0] = "soochow";
	fin << n << " " << m << endl;
	for (int i = 1; i <= m; ++i) {
		int p, len;
		p = rand() % n + 1;
		len = rand() % 50 + 1;
		if (rand() % 6 != 7) 
			s[i] = s[i - 1];
		else {
			for (int j = 0; j < len; j++)
				s[i] += (char)(rand() % 26 + 'a');
		}
		fin << p << " " << s[i] << endl;
	}
	fin.close();
}

void output(int id) {
	string in = to_string(id) + ".in";
	string out = to_string(id) + ".out";
	system((string("python3 prog.py < ") + in + " > " + out).c_str());
}

int main() {
	srand(time(NULL));
	for(int i = 12; i <= 12; ++i) {
		input(i);
		output(i);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

string input, output;

int id[100010];

void onedata(int limit) {
	ofstream fout(input);
	int n = 2 + rand() % (limit - 1), m = 1 + rand() % n;
	fout << n << " " << m << endl;
	for(int i = 1; i <= n; ++i) {
		fout << rand() % 2 << " ";
	}
	fout << endl;
	for(int i = 1; i <= n; ++i) {
		id[i] = i;
	}
	random_shuffle(id + 2, id + n + 1);
	for(int i = 2; i <= n; ++i) {
		int fa = 1 + rand() % (i - 1);
		if(rand() % 2)
			fout << id[i] << " " << id[fa] << endl;
		else
			fout << id[fa] << " " << id[i] << endl;
	}
	fout.close();
}

int main() {
	srand(time(NULL));
	for(int i = 1; i <= 10; ++i) {
		input = "data";
		input += to_string(i);
		output = input;
		input += ".in";
		output += ".out";
		if(i <= 2)
			onedata(20);
		else if(i <= 4)
			onedata(1000);
		else
			onedata(100000);
		system("g++ ans.cpp");
		system((string("./a.out < ") + input.c_str() + " > " + output.c_str()).c_str());
	}
	return 0;
}
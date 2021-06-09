#include <bits/stdc++.h>
using namespace std;


int main() {
	srand(time(NULL));
	for(int _ = 21; _ <= 25; ++_) {
		string str = "problem12/";
		str += to_string(_);
		str += ".in";
		ofstream fout(str, ios::out);
		int T = 20;
		fout << T << endl;
		while(T--) {
			int x = rand() % 90 - 39, y = rand() % 90 - 39;
			if(x > y) 
				swap(x, y);
			if(x == y)
				if(x != 50)
					y++;
			else
				x--;
			fout << x << " " << y << endl;
		}
	}	
	return 0;
}
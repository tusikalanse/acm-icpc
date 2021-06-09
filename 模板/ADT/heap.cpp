#include <bits/stdc++.h>
using namespace std;

template <typename T>
class heap {//大根堆， 父节点大于子节点
	static const int MAXN = 10010;
	T data[MAXN];
	int top;
public:
	heap(int _t = 0) : top(_t) {}
	void up(int p) {
		while(p > 1)
			if(data[p] > data[p >> 1]) {
				swap(data[p], data[p >> 1]);
				p >>= 1;
			}
			else 
				break;
	}
	void insert(T val) {
		data[++top] = val;
		up(top);
	}
	void down(int p) {
		int s = p << 1;
		while(s <= top) {
			if(s < top && data[s] < data[s | 1])
				s |= 1;
			if(data[s] > data[p]) {
				swap(data[s], data[p]);
				p = s;
				s <<= 1;
			}
			else
				break;
		}
	}
	void pop() {
		data[1] = data[top--];
		down(1);
	}
	T gettop() {
		return data[1];
	}
	void remove(int k) {
		data[k] = data[top--];
		up(k);
		down(k);
	}
};

int main() {
	return 0;
}
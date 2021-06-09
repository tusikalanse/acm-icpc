#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

void ReadFile(string ifname, vector<string> &A);
void ShowData1(vector<string> &A, int num, int wid);
vector<int> GetNumbers(vector<string> &A);
void ShowData2(vector<int> &B, int num, int wid);
void SortData(vector<int> &B);
bool cmp(int i, int j);
void WriteFile(string ofname, vector<int> &B);

int main()
{
	string ifname="d:\\input.txt",ofname="d:\\result.txt";
	vector<string> A;
	vector<int> B;

	ReadFile(ifname,A);
	
	cout<<"文件读取操作完成后的A向量为:"<<endl;
	ShowData1(A,5,15);
	cout<<endl;

	B=GetNumbers(A);
	cout<<"整数提取操作完成后的B向量为:"<<endl;
	ShowData2(B,5,10);
	cout<<endl;

	SortData(B);
	cout<<"排序操作完成后的B向量为:"<<endl;
	ShowData2(B,6,10);
	cout<<endl;

	WriteFile(ofname, B);
	return 0;
}

void ReadFile(string ifname, vector<string> &A) {
	ifstream fin(ifname.c_str());
	string str;
	while(fin >> str)
		A.push_back(str);
}

void ShowData1(vector<string> &A, int num, int wid) {
	int cnt = 0;
	for(int i = 0; i < A.size(); i++) {
		cnt++;
		cout << setw(wid) << left << A[i] << (cnt%num ? "" : "\n");
	}
	cout << (cnt%num ? "\n" : "");
}

vector<int> GetNumbers(vector<string> &A) {
	vector<int> B;
	for(int i = 0; i < A.size(); i++) {
		istringstream iss(A[i]);
		int num;
		if(iss >> num)
			B.push_back(num);
	}
	return B;
}

void ShowData2(vector<int> &B, int num, int wid) {
	int cnt = 0;
	for(int i = 0; i < B.size(); i++) {
		cnt++;
		cout << setw(wid) << left << B[i] << (cnt%num ? "" : "\n");
	}
	cout << (cnt%num ? "\n" : "");
}

bool cmp(int i, int j) {
	double i1 = 0, j1 = 0;
	int digit_i = 0, digit_j = 0;
	while(i) {
		digit_i++;
		i1 += i%10;
		i /= 10;
	}
	while(j) {
		digit_j++;
		j1 += j%10;
		j /= 10;
	}
	return (i1/digit_i) < (j1/digit_j);
}

void SortData(vector<int> &B) {
	sort(B.begin(), B.end(), cmp);
}

void WriteFile(string ofname, vector<int> &B) {
	ofstream fout(ofname.c_str());
	int cnt = 0;
	for(int i = 0; i < B.size(); i++) {
		cnt++;
		fout << setw(5) << right << B[i] << (cnt%4 ? "" : "\n");
	}
	fout << (cnt%4 ? "\n" : "");
}
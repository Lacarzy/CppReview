#include<iostream>
#include<vector>
#include"ShellSort.h"
using namespace std;
int main()
{
	int a[6] = { 3,4,5,2,1,6 };
	vector<int>b(a, a + 6);
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	ShellSort<int>(b);
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	getchar();
}
#include<iostream>
#include<vector>
#include"InsertSort.h"
using namespace std;
int main()
{
	int a[6] = { 2,3,5,1,4,6 };
	vector<int>b(a, a + 6);
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	InsertSort<int>(b);
	cout << endl;
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	getchar();
}
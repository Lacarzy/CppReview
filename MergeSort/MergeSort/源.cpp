#include<iostream>
#include<vector>
#include"MergeSort.h"
using namespace std;
int main()
{
	int test[6] = { 3,4,2,1,6,5 };
	vector<int>input(test, test + 6);
	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " ";
	}
	MergeSort<int>(input);
	cout << endl;
	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " ";
	}
	getchar();
}
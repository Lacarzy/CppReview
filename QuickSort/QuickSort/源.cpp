#include<iostream>
#include<vector>
#include"QuickSort.h"
using namespace std;
int main()
{
	int test[10] = { 1,2,5,10,9,8,1,5,6,7 };
	vector<int>nums(test, test + 10);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] <<" ";
	}
	quicksort<int>(nums);
	cout << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	getchar();
}
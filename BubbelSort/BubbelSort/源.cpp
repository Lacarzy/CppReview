#include<iostream>
#include<vector>
#include"BubbelSort.h"
using namespace std;
int main()
{
	int test[6] = { 2,5,1,6,3,4 };
	vector<int>nums(test,test+6);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	BubbelSort<int>(nums);
	cout << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	getchar();
}
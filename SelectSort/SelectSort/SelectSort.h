#ifndef SELECTSORT_H
#define SELECTSORT_H
//选择排序
//平均时间复杂度：O(N^2)
//最坏时间复杂度：O(N^2)
//最好时间复杂度：0(N^2)
//空间复杂度：0(1)
//不稳定排序
#include<vector>
using namespace std;
template<typename T>
void SelectSort(vector<T>&_nums)
{
	if (_nums.size() <= 1)
	{
		return;
	}
	for (int i = 0; i < _nums.size(); i++)
	{
		//T min = _nums[i];
		//int index = i;
		int swap_index = i;
		for (int j = i + 1; j < _nums.size(); j++)
		{
			if (_nums[j] < _nums[swap_index])
			{
				//min = _nums[j];
				//index = j;
				swap_index = j;
			}
		}
		//_nums[index] = _nums[i];
		//_nums[i] = min;
		if (swap_index != i);
		{
			swap(_nums[swap_index], _nums[i]);
		}
	}
}
#endif // !SELECTSORT_H


#ifndef SHELLSORT_H
#define SHELLSORT_H
//希尔排序
//最坏情况复杂度O(N^2)
//不稳定排序
#include<vector>
using namespace std;
template<typename T>
void ShellSort(vector<T>&_nums)
{
	int n = _nums.size();
	if (n <= 1)
	{
		return;
	}
	for (int increment = n / 2; increment > 0; increment /= 2)//增量
	{
		for (int i = increment; i < n; i++)//每个元素都进行插入尝试
		{
			int insert_num=_nums[i],j;
			for (j = i - increment; j >= 0; j -= increment)//与前面的每一元素进行比较
			{
				if (insert_num < _nums[j])
					_nums[j + increment] = _nums[j];
				else
					break;
			}
			_nums[j + increment] = insert_num;
		}
	}
}
#endif // !SHELLSORT_H


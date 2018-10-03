#ifndef BUBBELSORT_H
#define BUBBELSORT_H

#include<vector>
using namespace std;
//基本冒泡排序
//平均时间复杂度：O(n^2)
//最坏情况复杂度：O(n^2)
//空间复杂度：O(1)
//稳定排序
template<typename T>
void BubbelSort(vector<T>& _nums)
{
	for (int i = 0; i < _nums.size(); i++)
	{
		for (int j = 0; j < _nums.size() - 1 - i; j++)
		{
			if (_nums[j] > _nums[j + 1])
				swap(_nums[j], _nums[j + 1]);
		}
	}
};
//简单优化1
template<typename T>
void BubbelSort2(vector<T>&_nums)
{
	bool flag;
	for (int i = 0; i < _nums.size(); i++)
	{
		flag = false;//添加标记位
		for (int j = 0; j < _nums.size() - 1 - i; j++)
		{
			if (_nums[j] > _nums[j + 1])
			{
				swap(_nums[j], _nums[j + 1]);
				flag = true;//发生交换
			}
		}
		if (!flag)//该趟没有发生交换，即代表已排好
			break;
	}
};
//升级优化2
template<typename T>
void BubbelSort3(vector<T>&_nums)
{
	int flag = _nums.size();
	int stop_pos;
	for (int i = 0; i < _nums.size(); i++)
	{
		stop_pos = flag - 1;
		flag = 0;
		for (int j = 0; j < stop_pos; j++)
		{
			if (_nums[j] > _nums[j + 1])
			{
				swap(_nums[j], _nums[j + 1]);
				flag = j + 1;//保存最后发生交换的位置，该位置后的数据已有序不需要再比
			}
		}
		if (flag == 0)//若全部排好，则flag=0,所以涵盖了优化1的效果；
			break;
	}
};
#endif // !BUBBELSORT_H


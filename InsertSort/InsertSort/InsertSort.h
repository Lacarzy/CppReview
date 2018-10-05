#ifndef INSERTSORT_H
#define INSERTSORT_H
//插入排序
//平均时间复杂度：O(N^2)
//最坏情况复杂度：O(N^2)
//最好情况复杂度：O(N)
//空间复杂度：O(1)
//最多需n(n-1)/2次比较
//最少需要n-1次比较
//稳定排序
#include<vector>
using namespace std;
template<typename T>
void InsertSort(vector<T>&_nums)
{
	int n = _nums.size();
	if (n <= 1)
	{
		return;
	}
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		T temp = _nums[i];
		while (j >= 0 && temp<_nums[j])
		{
			_nums[j + 1] = _nums[j];
			j = j - 1;
		}
		_nums[j + 1] = temp;
	}
}
#endif // !INSERTSORT_H


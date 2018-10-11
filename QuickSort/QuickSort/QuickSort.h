#ifndef QUICKSORT_H
#define QUICKSORT_H
//快速排序
//不稳定排序
//平均时间复杂度：O(NlogN)
//最坏情况复杂度：O(N^2)
#include<vector>
using namespace std;
//template<typename T>
//void quicksortHelper(vector<T>& _nums,int start,int end)
//{
//	if (start >= end)
//	{
//		return;
//	}
//	int l = start, r = end;
//	int pivot = _nums[(end - start) / 2 + start];
//	while (l<=r)
//	{
//		while (l<=r&&_nums[r]>pivot)
//		{
//			r--;
//		};
//		while (l<=r&&_nums[l]<pivot)
//		{
//			l++;
//		};
//		if (l <= r)
//		{
//			swap(_nums[l++], _nums[r--]);
//		}
//		quicksortHelper(_nums, start, r);
//		quicksortHelper(_nums, l, end);
//	}
//}
template<typename T>
void QuicksortHelper(vector<T>&_nums, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int l = left, r = right;
	int pivot = _nums[left];//左边第一个为标杆
	//一轮快排
	while (l<r)
	{
		while (l < r)//右边开始扫
		{
			if (_nums[r] > pivot)//比标杆大的不用管
			{
				r--;
			}
			else//小的把值赋给左边的坑然后自己成为新坑
			{
				_nums[l] = _nums[r];
				l++;
				break;
			}
		}
		while (l<r)//右边扫完左边扫
		{
			if (_nums[l] < pivot)//比标杆小的不用管
			{
				l++;
			}
			else//大的赋值给右边的坑然后自己成为新坑
			{
				_nums[r] = _nums[l];
				r--;
				break;
			}
		}
	}
	_nums[l] = pivot;//最后把标杆值填回最后的坑里
	//一轮快排结束l==r
	QuicksortHelper(_nums, left, l - 1);
	QuicksortHelper(_nums, r + 1, right);

}

template<typename T>
void quicksort(vector<T>&_nums)
{
	QuicksortHelper(_nums, 0, _nums.size() - 1);
}
#endif // !QUICKSORT_H

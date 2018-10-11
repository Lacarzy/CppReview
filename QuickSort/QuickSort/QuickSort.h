#ifndef QUICKSORT_H
#define QUICKSORT_H
//��������
//���ȶ�����
//ƽ��ʱ�临�Ӷȣ�O(NlogN)
//�������Ӷȣ�O(N^2)
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
	int pivot = _nums[left];//��ߵ�һ��Ϊ���
	//һ�ֿ���
	while (l<r)
	{
		while (l < r)//�ұ߿�ʼɨ
		{
			if (_nums[r] > pivot)//�ȱ�˴�Ĳ��ù�
			{
				r--;
			}
			else//С�İ�ֵ������ߵĿ�Ȼ���Լ���Ϊ�¿�
			{
				_nums[l] = _nums[r];
				l++;
				break;
			}
		}
		while (l<r)//�ұ�ɨ�����ɨ
		{
			if (_nums[l] < pivot)//�ȱ��С�Ĳ��ù�
			{
				l++;
			}
			else//��ĸ�ֵ���ұߵĿ�Ȼ���Լ���Ϊ�¿�
			{
				_nums[r] = _nums[l];
				r--;
				break;
			}
		}
	}
	_nums[l] = pivot;//���ѱ��ֵ������Ŀ���
	//һ�ֿ��Ž���l==r
	QuicksortHelper(_nums, left, l - 1);
	QuicksortHelper(_nums, r + 1, right);

}

template<typename T>
void quicksort(vector<T>&_nums)
{
	QuicksortHelper(_nums, 0, _nums.size() - 1);
}
#endif // !QUICKSORT_H

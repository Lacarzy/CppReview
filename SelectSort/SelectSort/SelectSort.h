#ifndef SELECTSORT_H
#define SELECTSORT_H
//ѡ������
//ƽ��ʱ�临�Ӷȣ�O(N^2)
//�ʱ�临�Ӷȣ�O(N^2)
//���ʱ�临�Ӷȣ�0(N^2)
//�ռ临�Ӷȣ�0(1)
//���ȶ�����
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


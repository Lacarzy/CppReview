#ifndef INSERTSORT_H
#define INSERTSORT_H
//��������
//ƽ��ʱ�临�Ӷȣ�O(N^2)
//�������Ӷȣ�O(N^2)
//���������Ӷȣ�O(N)
//�ռ临�Ӷȣ�O(1)
//�����n(n-1)/2�αȽ�
//������Ҫn-1�αȽ�
//�ȶ�����
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


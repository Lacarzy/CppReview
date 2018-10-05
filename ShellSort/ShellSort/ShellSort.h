#ifndef SHELLSORT_H
#define SHELLSORT_H
//ϣ������
//�������Ӷ�O(N^2)
//���ȶ�����
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
	for (int increment = n / 2; increment > 0; increment /= 2)//����
	{
		for (int i = increment; i < n; i++)//ÿ��Ԫ�ض����в��볢��
		{
			int insert_num=_nums[i],j;
			for (j = i - increment; j >= 0; j -= increment)//��ǰ���ÿһԪ�ؽ��бȽ�
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


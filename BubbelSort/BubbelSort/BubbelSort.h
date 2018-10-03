#ifndef BUBBELSORT_H
#define BUBBELSORT_H

#include<vector>
using namespace std;
//����ð������
//ƽ��ʱ�临�Ӷȣ�O(n^2)
//�������Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O(1)
//�ȶ�����
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
//���Ż�1
template<typename T>
void BubbelSort2(vector<T>&_nums)
{
	bool flag;
	for (int i = 0; i < _nums.size(); i++)
	{
		flag = false;//��ӱ��λ
		for (int j = 0; j < _nums.size() - 1 - i; j++)
		{
			if (_nums[j] > _nums[j + 1])
			{
				swap(_nums[j], _nums[j + 1]);
				flag = true;//��������
			}
		}
		if (!flag)//����û�з������������������ź�
			break;
	}
};
//�����Ż�2
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
				flag = j + 1;//���������������λ�ã���λ�ú��������������Ҫ�ٱ�
			}
		}
		if (flag == 0)//��ȫ���źã���flag=0,���Ժ������Ż�1��Ч����
			break;
	}
};
#endif // !BUBBELSORT_H


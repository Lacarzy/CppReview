#ifndef HEAPSORT_H
#define HEAPSORT_H
#include<vector>
using namespace std;
//������
//����ƽ��ʱ���ǣ�O(N)
//�����ʱ���ǣ�O(NLogN)
//ɾ��Ԫ�ص�ʱ���ǣ�O(NlogN)
//���������ƽ��ʱ�临�Ӷ��ǣ�O(N+NlogN)=O(NlogN)
//�ʱ�临�Ӷ��ǣ�O(NlogN)
//���ȶ�����
template<typename T>
void make_heap(vector<T>&_nums,int size)//�������ѣ����ڵ���±�Ϊ0������������Ϊ2n+1��������,������Ϊ2n+2��ż����
{
	for (int i = size - 1; i > 0; i--)
	{
		if (i%2 == 0 && _nums[i] > _nums[(i - 2) / 2])//ż��
			swap(_nums[i], _nums[(i - 2) / 2]);
		else if(i%2==1&&_nums[i]>_nums[(i-1)/2])//����
		{
			swap(_nums[i], _nums[(i - 1) / 2]);
		}
	}
}
template<typename T>
void HeapSort(vector<T>&_nums)
{
	int n = _nums.size();
	while (n)
	{
		make_heap(_nums, n);//����
		n--;
		swap(_nums[0], _nums[n]);//�Ѹ��ڵ�ŵ���������ټ���Ԫ�����½���
	}
}
#endif // 

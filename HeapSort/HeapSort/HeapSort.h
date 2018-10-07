#ifndef HEAPSORT_H
#define HEAPSORT_H
#include<vector>
using namespace std;
//堆排序
//建堆平均时间是：O(N)
//建堆最坏时间是：O(NLogN)
//删除元素的时间是：O(NlogN)
//整个排序的平均时间复杂度是：O(N+NlogN)=O(NlogN)
//最坏时间复杂度是：O(NlogN)
//不稳定排序
template<typename T>
void make_heap(vector<T>&_nums,int size)//建立最大堆，根节点的下标为0，所以左子树为2n+1（基数）,右子树为2n+2（偶数）
{
	for (int i = size - 1; i > 0; i--)
	{
		if (i%2 == 0 && _nums[i] > _nums[(i - 2) / 2])//偶数
			swap(_nums[i], _nums[(i - 2) / 2]);
		else if(i%2==1&&_nums[i]>_nums[(i-1)/2])//奇数
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
		make_heap(_nums, n);//建堆
		n--;
		swap(_nums[0], _nums[n]);//把根节点放到数组最后，再减少元素重新建堆
	}
}
#endif // 

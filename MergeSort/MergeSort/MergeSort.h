#ifndef MERGESORT_H
#define MERGESORT_H
#include<vector>
using namespace std;
//归并排序
//平均时间复杂度：O(NlogN)
//稳定排序
template<typename T>
vector<T> MergeHelper(vector<T>&_nums, int left, int right)
{
	if (left == right)
	{ 
		//vector<T>ret(1, _nums[left]);
		//return ret;
		//return vector<T>ret(1, _nums[left]);
		return vector<T>(1, _nums[left]);
	}
	int mid = (right - left) / 2 + left;
	vector<T>l = MergeHelper(_nums, left, mid);
	vector<T>r = MergeHelper(_nums, mid + 1, right);
	//merge
	vector<T>ret;
	int ll = 0, rr = 0;
	while(ll < l.size() && rr < r.size())
	{
		if (l[ll] <= r[rr])
			ret.push_back(l[ll++]);
		else
			ret.push_back(r[rr++]);
	}
	while (ll < l.size())
		ret.push_back(l[ll++]);
	while (rr < r.size())
		ret.push_back(r[rr++]);
	return ret;
}
template<typename T>
void MergeSort(vector<T>&_nums)
{
	_nums = MergeHelper(_nums, 0, _nums.size() - 1);
}
#endif // !MERGESORT_H


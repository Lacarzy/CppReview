#ifndef MAXHEAP_H
#define MAXHEAP_H
using namespace std;
//大顶堆定义
template<typename T>
class MaxHeap
{
public:
	MaxHeap(int cap = 10);
	~MaxHeap();
public:
	bool insert(T val);	//插入元素
	bool remove(T data);	//移除元素
	void print();			//打印堆
	T getTop();				//获取堆顶元素
	bool createMaxHeap(T a[], int size);//根据指定数组来创建一个最大堆
private:
	int capacity;			//容量，即数组大小
	int size;				//堆大小
	T*heap;					//底层为数组
private:
	void filterUp(int index);//从index所在节点往根节点调整堆
	void filterDown(int begin, int end);//从begin所在节点开始向end方向调整堆
};

//默认构造函数
template<typename T>
MaxHeap<T>::MaxHeap(int cap)
	:capacity(cap), size(0), heap(nullptr)
{
	heap = new T[capacity];
};

//析构函数
template<typename T>
MaxHeap<T>::~MaxHeap()
{
	delete[] heap;
};

//打印大顶堆
template<typename T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
};

//获取堆顶元素
template<typename T>
T MaxHeap<T>::getTop()
{
	if (size != 0)
		return heap[0];
};

//插入元素
template<typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity)//如果数组已满，则返回false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
};

//从下到上调整堆
//插入元素时候使用
template<typename T>
void MaxHeap<T>::filterUp(int index)
{
	T value = heap[index];//插入节点的值
	while (index>0)//还没到达根节点
	{
		int indexParent = (index - 1) / 2;//求其双亲节点
		if (value < heap[indexParent])
			break;
		else
		{
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;//插入最后替换的位置
};

//根据指定的数组来创建一个最大堆
template<typename T>
bool MaxHeap<T>::createMaxHeap(T a[], int size)
{
	if (size > capacity)
		return false;
	for (int i = 0; i < size; i++)
	{
		insert(a[i]);
	}
	return true;
};

//删除元素
template<typename T>
bool MaxHeap<T>::remove(T data)
{
	if (size == 0)//堆空
		return false;
	int index;
	for (index = 0; index < size; index++)
	{
		if (heap[index] == data)
			break;
	}
	if (index==size)//没找到该值
	{
		return false;
	}
	heap[index] = heap[size - 1];//最后一个节点代替当前结点，然后向下调整
	filterDown(index, --size);
	return true;
};

//从上到下调整堆
//删除元素时使用
template<typename T>
void MaxHeap<T>::filterDown(int current, int end)
{
	int child = current * 2 + 1;//当前节点的左孩子
	T value = heap[current];//保存当前节点的值
	while (child<=end)
	{
		if (child < end&&heap[child] < heap[child + 1])//选出两个孩子中较大的孩子
			child++;
		if (value > heap[child])//无需调整
			break;
		else
		{
			heap[current] = heap[child];
			current = child;//向下移动
			child = child * 2 + 1;
		}
	}
	heap[current] = value;
};
#endif // !MAXHEAP_H


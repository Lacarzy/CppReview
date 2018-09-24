#ifndef LOOPQUEUE_H
#define LOOPQUEUE_H
//tip：
//队空：队首标志=队尾标志
//队满：队尾+1=队首 （与队空区分）
template<typename T>
class LoopQueue
{
public:
	LoopQueue(int c = 10);
	~LoopQueue();
public:
	bool isEmpty();//队列的判空
	int size();//队列的大小
	bool push(T t);//入队列
	bool pop();//出队列
	T front();//队首元素
private:
	int capacity;
	int begin;
	int end;
	T* queue;
};

template<typename T>
LoopQueue<T>::LoopQueue(int c)
	:capacity(c), begin(0), end(0), queue(nullptr)
{
	queue = new T[capacity];
};

template<typename T>
LoopQueue<T>::~LoopQueue()
{
	delete[] queue;
};

template<typename T>
bool LoopQueue<T>::isEmpty()
{
	return begin == end;
};

template<typename T>
int LoopQueue<T>::size()
{
	return (end - begin + capacity) % capacity;//计算队列长度
};

template<typename T>
bool LoopQueue<T>::push(T t)
{
	if (end + 1 % capacity == begin)//判断队列是否已满
	{
		return false;
	}
	queue[end] = t;
	end = (end + 1) % capacity;
	return true;
};

template<typename T>
bool LoopQueue<T>::pop()
{
	if (isEmpty())//判断队列是否为空
	{
		return false;
	}
	begin = (begin + 1) % capacity;
	return true;
};

template<typename T>
T LoopQueue<T>::front()
{
	if (isEmpty())
	{
		return false;//隐式转换T类型需要有bool转T的隐式转换才不会报错
	}
	return queue[begin];
};
#endif
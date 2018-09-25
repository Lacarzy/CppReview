#ifndef LINKQUEUE_H
#define LINKQUEUE_H
template<typename T>
struct Node
{
	Node() = default;
	Node(T t) :value(t), next(nullptr) {}
	T value;
	Node<T>*next;
};
template<typename T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();

	bool isEmpty();
	int size();
	bool pop();
	void push(T t);
	T front();
private:
	Node<T>* phead;
	Node<T>* pend;
	int count;
};
template<typename T>
LinkQueue<T>::LinkQueue()
	:phead(nullptr),pend(nullptr),count(0)
{
	phead = new Node<T>();
	pend = phead;
	count = 0;
};
template<typename T>
LinkQueue<T>::~LinkQueue()
{
	while (phead->next != nullptr)
	{
		Node<T>*pnode = phead;
		phead = phead->next;
	}
};
template<typename T>
bool LinkQueue<T>::isEmpty()
{
	return count == 0;
};
template<typename T>
int LinkQueue<T>::size()
{
	return count;
};
//�ڶ�β����
template<typename T>
void LinkQueue<T>::push(T t)
{
	Node<T>*pnode = new Node<T>(t);
	pend->next = pnode;
	pend = pnode;
	count++;
};
//�ڶ��׵���
template<typename T>
bool LinkQueue<T>::pop()
{
	if (count == 0)
		return false;
	Node<T>*pnode = phead->next;
	phead->next = phead->next->next;
	delete pnode;
	count--;
	return true;
};
//��ȡ����Ԫ��
template<typename T>
T LinkQueue<T>::front()
{
	return phead->next->value;
};
#endif
#include<iostream>
#include"ArrayStack.h"
using namespace std;
int main()
{
	ArrayStack<int>p(5);
	for (int i = 0; i < 5; i++)
	{
		p.push(i);
	}
	cout << "ջ�Ĵ�С:" << p.size() << endl;
	cout << "ջ�Ƿ�Ϊ�գ�" << p.isEmpty() << endl;
	cout << "ջ��Ԫ�أ�" << p.top() << endl;
	cout << "���γ�ջ��" << endl;
	while (!p.isEmpty())
	{
		cout << p.pop() << endl;
	}
	getchar();
	return 0;
}
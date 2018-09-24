#include<iostream>
#include"LoopQueue.h"
using namespace std;
double test()
{
	return false;
}
class mydata
{
	int a;
	char b;
public:
	mydata(int _a, char _b)
	{
		a = _a;
		b = _b;
	}
};
int main()
{
	LoopQueue<int>queue(6);
	cout<<queue.front();
	getchar();
	return 0;
}

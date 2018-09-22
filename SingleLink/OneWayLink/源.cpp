#include<iostream>
#include"Singlelink.h"
using namespace std;
int main()
{
	SingleLink<int>linka;
	int num;
	cin >> num;
	linka.insert_head(num);
	cout << linka.getHead()->_value;
	system("pause");
	
}
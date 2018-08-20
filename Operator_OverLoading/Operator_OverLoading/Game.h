#pragma once
#include<string>;
using namespace std;
class Game
{
private:
	string name;
	double price;
	string type;
	double size;
public:
	Game(string _name,double _price,string _type,double _size);
	double operator+(const Game & temp);//����ֵ��ͬ���Ͳ���Ҫ����Ԫ;
	double operator*(const int & num) const;//����������Ϸ�����ܼۣ�������������ֻ������Game*int����������int*Game;
	friend double operator*(const int & num, const Game& temp);//ʹ����Ԫ��������int*Game��������Ա��������;
	friend ostream& operator<<(ostream&os, const Game& temp);//��������Ϊostream�����ڶ��<<�������;
	bool operator==(const Game& temp);
	~Game();
};


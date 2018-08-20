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
	double operator+(const Game & temp);//左右值相同类型不需要用友元;
	double operator*(const int & num) const;//假设买多个游戏，算总价，单纯这样重载只能满足Game*int，不能满足int*Game;
	friend double operator*(const int & num, const Game& temp);//使用友元可以满足int*Game，跳出成员函数局限;
	friend ostream& operator<<(ostream&os, const Game& temp);//返回类型为ostream可用于多个<<连续输出;
	bool operator==(const Game& temp);
	~Game();
};


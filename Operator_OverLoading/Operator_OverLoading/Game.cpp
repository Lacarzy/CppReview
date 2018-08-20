#include "Game.h"



Game::Game(string _name, double _price, string _type, double _size)
{
	this->name = _name;
	this->price = _price;
	this->type = _type;
	this->size = _size;
}


bool Game::operator==(const Game & temp)
{
	if (temp.name==this->name&&temp.price==this->price&&temp.size==this->size&&temp.type==this->type){
		return true;
	}
	else
	{
		return false;
	}
}

Game::~Game()
{
}

double Game::operator+(const Game& temp) {
	double result;
	result = temp.price + this->price;
	return result;
}
double Game::operator*(const int& num) const{
	double result;
	result = num * this->price;
	return result;
}

double operator*(const int & num, const Game & temp)
{
	double result;
	result = temp * num;//调换左右值，简单调用前面的运算符重载;
	return result;
}

ostream& operator<<(ostream&os, const Game & temp) {
	os << "Game_Name: " << temp.name << endl << "Game_Price: " << temp.price << endl << "Game_Type: " << temp.type << endl << "Game_Size:" << temp.size << endl;
	return os;
}
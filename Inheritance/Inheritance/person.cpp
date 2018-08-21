#include "person.h"



person::person(const string &_name, const int & _age, const double & _height, const double & _widget)
{
	this->name = _name;
	this->age = _age;
	this->height = _height;
	this->widget = _widget;
}

void person::changeName(const string & newname) 
{	
	this->name = newname;
}

void person::setAge(const int & newage)
{
	this->age = newage;
}

person::~person()
{
}

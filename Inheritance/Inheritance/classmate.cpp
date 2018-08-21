#include "classmate.h"
#include<iostream>
using namespace std;

classmate::classmate(const string &_name, const int & _age, const double & _height, const double & _widget,const char*_nickname, const int&_grade, const double&_friendlyRate):person(_name,_age,_height,_widget)
{
	this->friendlyRate = _friendlyRate;
	this->grade = _grade;
	this->nickname = new char[strlen(_nickname) + 1];
	strcpy_s(this->nickname, strlen(nickname) + 1, _nickname);
}

void classmate::Relasionship()
{
	cout << "You are the classmate in " << this->grade<<endl<<"You call the guy "<<this->nickname<<endl;
}


classmate::~classmate()
{
	delete nickname;
}

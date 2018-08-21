#pragma once
#include "person.h"
class classmate :
	public person
{
private:
	int grade;
	char *nickname;
	double friendlyRate;
public:
	classmate(const string &_name, const int & _age, const double & _height, const double & _widget,const char*_nickname,const int&_grade,const double&_friendlyRate);
	virtual void Relasionship();
	~classmate();
};


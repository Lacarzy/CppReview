#pragma once
#include<string>
using namespace std;
class person
{
private:
	string name;
	int age;
	double height;
	double widget;
public:
	person(const string &_name,const int & _age,const double & _height,const double & _widget);
	void changeName(const string & newname);
	void setAge(const int & newage);
	virtual void Relasionship() = 0;
	virtual ~person();
};


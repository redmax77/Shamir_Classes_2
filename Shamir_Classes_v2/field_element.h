#pragma once
#include <iostream>
using namespace std;

// drop number in field 

class field_element
{
public:

	field_element();
	field_element(int _characteristic);
	field_element(int _element, int _characteristic);
	virtual ~field_element();

	int get_element() { return element; }
	int get_characteristic() { return characteristic; }
	void set_element(int _element) { (_element > 0) ? element = _element % characteristic : element = (_element % characteristic) + characteristic;}
	int get_inverse(int _element);

	field_element operator+(field_element right);
	field_element operator+(int right);
	field_element operator*(field_element right);
	field_element operator*(int right);
	
	friend ostream &operator<<(ostream &stream, field_element f);
	friend field_element &operator+=(field_element &left, field_element &right);

private:
	int element, characteristic;
};


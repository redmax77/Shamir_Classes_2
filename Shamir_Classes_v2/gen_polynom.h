#pragma once
#include "field_element.h"
#include <vector>

class gen_polynom
{
public:
	gen_polynom(int degree, int characteristic);
	virtual ~gen_polynom();

	int get_secret() { return polynom.front(); };
	int* get_polynom(){ return &polynom[0]; };
	int get_degree() { return _degree; };
protected:
	int _degree;
	int _characteristic;
	vector<int> polynom;
};


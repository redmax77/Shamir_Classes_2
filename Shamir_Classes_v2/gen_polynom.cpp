#include "stdafx.h"
#include "gen_polynom.h"
#include <ctime>

//generate polynom  in field 
// you can use any polynom degree
// also return secret
gen_polynom::gen_polynom(int degree, int characteristic)
{
	srand(time(NULL));
	int i;
	_degree = degree;
	_characteristic = characteristic;

	for (i = 0; i < _degree; i++)
	{
		field_element f(rand(), characteristic);
		polynom.push_back(f.get_element());
	}
}

gen_polynom::~gen_polynom()
{
}

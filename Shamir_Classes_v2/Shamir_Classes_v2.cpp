#include "stdafx.h"
#include "field_element.h"
#include <vector>
#include "gen_polynom.h"
#include "calc_polynom.h"

int main()
{
	int i, j;
	vector<int> p;

	//gen_polynom pol(5, 88);
	//cout << endl << endl << pol.get_secret();
	
	//int *vecror_pol = pol.get_polynom();
	//cout << endl << *(vecror_pol+5);
	/*
	field_element f(5, 6);
	cout << f.get_element();
	f = f * 2;
	cout << f.get_element();
	*/
	for (i = 0; i < 10; i++)
	{
		j = i + 1;
		p.push_back(j);
	}

	calc_polynom(10, 17, &p);


	system("PAUSE");
    return 0;
}


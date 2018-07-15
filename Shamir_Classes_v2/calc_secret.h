#pragma once
#include "field_element.h"
#include <vector>

class calc_secret
{
public:
	calc_secret(int characteristic, int degree);
	virtual ~calc_secret();

	int get_recover_secret() { return recover_secrer; }
	int recover_polynom_secret_use_points(int *arr_points, int &vec_arr_points);
	int recover_polynom_use_points_multiplicative_part_2(int *arr_points, int j);

private:
	int _degree;
	int _characteristic;
	int secret;
	int recover_secrer;
	int *_polynom = NULL;
	int *_polynom_res = NULL;
	vector <int> poly_res ;
	vector <int> poly;
};



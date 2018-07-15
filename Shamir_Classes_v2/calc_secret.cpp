#include "stdafx.h"
#include "calc_secret.h"

calc_secret::calc_secret(int characteristic, int degree)
{
	_characteristic = characteristic;
	_degree = degree;
}
calc_secret::~calc_secret()
{
}

int calc_secret::recover_polynom_use_points_multiplicative_part_2(int *arr_points, int j)
{
	int x = 1;
	int x1 = 1;
	int y = 1;
	int y1 = 1;
	int i;

	field_element f(_characteristic);
	field_element x2(_characteristic);
	field_element y2(_characteristic);
	//cout << "                       j = " << j << "   arr_points[" << j << "] = " << arr_points[j] << endl;
	for (i = 1; i < (_degree + 1); i++)
	{
		if (i != j)
		{
			//xi = xi [*, i!=j] (ri / (ri - rj)  % mod N)
			y = arr_points[i] - arr_points[j];
			if (y < 0) y = y + _characteristic;
			y = f.get_inverse(y);
			x = (x * arr_points[i] * y) % _characteristic;

			// ver 2 using  field_element
			y2 = y2.get_inverse(arr_points[i] - arr_points[j]); // (rj - ri)^-1
			x2 = x2 * arr_points[i];							// xi * ri
			x2 = x2 * y2;										//xi =  xi * (ri / (ri - rj) 	

		}
	}
	//cout << endl << "S(" << arr_points[j] << ") = " << x << endl;
	return x;
}
int calc_secret::recover_polynom_secret_use_points(int *arr_points, int &vec_arr_points)
{
	int i;
	int z = 0;
	int x = 0;
	field_element z1(_characteristic);
	field_element x1(_characteristic);

	for (i = 1; i < (_degree + 1); i++)
	{
		z = recover_polynom_use_points_multiplicative_part_2(arr_points, i);
		x = (x + (_polynom_res[arr_points[i]] * z)) % _characteristic;

		//ver 2 using field_element
		x1 =+ (_polynom_res[arr_points[i]] * z);

	}
	recover_secrer = x;
	//cout << endl << endl << "recover_secrer = " << recover_secrer;
	return recover_secrer;
}
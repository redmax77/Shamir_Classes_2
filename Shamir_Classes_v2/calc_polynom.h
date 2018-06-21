#pragma once
#include "gen_polynom.h"
#include "field_element.h"
class calc_polynom :
	public gen_polynom
{
public:
	int result;

	calc_polynom(int degree, int characteristic, vector<int>* users):gen_polynom(degree, characteristic)
	{
		int i;
		int tmp_tmp, tmp =0;
		_characteristic = characteristic;
		cout << endl;
		field_element res_from_x(0, _characteristic);
		for (i = 0; i < polynom.size(); i++)
		{
			res_from_x = res_from_x + calculate_part(i, users->at(i));


			tmp_tmp = calculate_part(i, users->at(i));
			tmp = tmp + calculate_part(i, users->at(i));
			cout << polynom[i] << " * " << users->at(i) << " ^ " << i << " = " << tmp_tmp << endl;
		}
		result = res_from_x.get_element();
		cout << endl << tmp % _characteristic << " = " << res_from_x.get_element() << " = " << result;
	};
	int calc_polynom_get_result() { return result; }
private:
	int calculate_part(int current_degree, int current_x)
	{
		field_element f(polynom[current_degree] * pow_god(current_x, current_degree), _characteristic);
		return f.get_element();
	}
	int pow_god(int j, int n)
	{
		int i;
		int counter = abs(n);
		field_element element_in_field(j, _characteristic);

		if (n == 0)
			return 1;

		else if (n == 1)
			return j;

		else if (n > 1)
		{
			for (i = 1; i < n; i++)
				element_in_field = element_in_field * j;
		}
		return element_in_field.get_element();;
	}
	int _characteristic;

};


#pragma once
#include "gen_polynom.h"
#include "field_element.h"
#include "users_values.h"

// calculate gen_polynom 
// in: degree, field characteristic, numbers of users.

class calc_polynom :
	public gen_polynom
{
public:
	int result;

	calc_polynom(int degree, int characteristic, int number_of_users, vector< vector <int> > &matrix):gen_polynom(degree, characteristic)
	{
		int i, j, tmp_tmp, tmp =0;

		_characteristic = characteristic;
		
		// vector UID
		vector <int> users_id;
		users_values vec(number_of_users);
		vec.generate_UID(users_id);

		cout << endl;
		cout << " calc polynom mod " << _characteristic <<  endl;

		
		for (j = 0; j < users_id.size(); j++)
		{
			std::vector<int> temp;
			field_element res_from_x(0, _characteristic);

			//calc f(current UID)		
			for (i = 0; i < polynom.size(); i++)
			{
				res_from_x = res_from_x + calculate_part(i, users_id.at(j));
				cout << endl << users_id.at(j) << endl;
				tmp_tmp = calculate_part(i, users_id.at(j));
				tmp = tmp + calculate_part(i, users_id.at(j));
				cout << polynom[i] << " * " << users_id.at(j) << " ^ " << i << " = " << tmp_tmp << "   current res = " << res_from_x << endl;
			}

			// Put in vector UID + f(UID)
			for (int k = 0; k < 2; k++)
			{
				if (k == 0) temp.push_back(users_id.at(j));
				if (k == 1) temp.push_back(tmp_tmp);
			}
			matrix.push_back(temp);


			cout << res_from_x << endl << endl << endl;
		}
		
		//cout UID + f(UID)
		for (int p = 0; p < number_of_users; p++) 
		{
			for (int l = 0; l<2; l++) 
				cout << matrix[p][l] << ' ';
			cout << endl; 
		}

	};
	
	int calc_polynom_get_result() { return result; }
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
			return element_in_field.get_element();

		else if (n > 1)
		{
			for (i = 1; i < n; i++)
				element_in_field = element_in_field * j;
		}
		return element_in_field.get_element();
	}
private:
	int _characteristic;

};


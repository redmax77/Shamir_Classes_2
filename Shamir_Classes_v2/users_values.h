#pragma once
#include <vector>

// generate UID and put them in vector
// use UID to calculate polynom.
class users_values
{
public:
	users_values(int _number_of_users);
	virtual ~users_values();

	int get_numb_of_users() { return number_of_users; }
	void generate_UID(std::vector<int> &users);

private:
	int number_of_users;
};


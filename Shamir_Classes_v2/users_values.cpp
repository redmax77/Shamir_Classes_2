#include "stdafx.h"
#include "users_values.h"

users_values::users_values(int _number_of_users)
{
	number_of_users = _number_of_users;
}


users_values::~users_values()
{
}

void users_values::generate_UID(std::vector<int> &users)
{
	//there is room for add smth more difficult
	int i;
	for (i = 0; i < number_of_users; i++)
	{
		users.push_back(i+1); // UID !=0
	}
}

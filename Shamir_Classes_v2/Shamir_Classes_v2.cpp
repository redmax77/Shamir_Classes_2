#include "stdafx.h"
#include "field_element.h"
#include "gen_polynom.h"
#include <vector>
#include "calc_polynom.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("tests field.h") {

	field_element f(5, 6);

	SECTION("get element")
	{
		REQUIRE(f.get_element() == 5);
	}
	SECTION("get characteristic")
	{
		REQUIRE(f.get_characteristic() == 6);
	}
	SECTION("field + int") 
	{
		f = f + 9;

		REQUIRE(f.get_element() == 2); //5 + 9 mod6
	}
	SECTION("field + field") 
	{
		f = f + f;

		REQUIRE(f.get_element() == 4); //5 + 5 mod6
	}
	SECTION("field * int") 
	{
		f = f * 8;

		REQUIRE(f.get_element() == 4); //5 * 8 mod6
	}
	SECTION("field * field") 
	{
		f = f * f;

		REQUIRE(f.get_element() == 1); //5 * 5 mod6
	}
	SECTION("field += field") 
	{
		f += f;

		REQUIRE(f.get_element() == 4); //7 mod6
	}
	SECTION("set element") 
	{
		f.set_element(77);

		REQUIRE(f.get_element() == 5); //7 mod6
	}
}

TEST_CASE("tests gen.h") {

	gen_polynom f(5, 6);

	SECTION("get degree")
	{
		REQUIRE(f.get_degree() == 5);
	}

	SECTION("get secret") 
	{
		REQUIRE(f.get_secret() < 6);
	}

	SECTION("get secret")
	{
		REQUIRE(f.get_secret() < 6);
	}

}

TEST_CASE("tests calc.h") {
	
	int numbers_of_users = 8;
	vector < vector <int> > a;

	calc_polynom f(10, 17, numbers_of_users, a);


	SECTION("pow 5^0 mod 17")
	{
		REQUIRE(f.pow_god(5,0) == 1);
	}
	SECTION("pow 5^1 mod 17")
	{
		REQUIRE(f.pow_god(5, 1) == 5);
	}
	SECTION("pow 18^1 mod 17 ")
	{
		REQUIRE(f.pow_god(18, 1) == 1);
	}
	SECTION("pow 18^2 mod 17 ")
	{
		REQUIRE(f.pow_god(18, 2) == 1);
	}
	SECTION("calculate x^i * k(i) ")
	{
		REQUIRE(f.calculate_part(7, 2) < 17);
	}
}

// TODO : add class to recover polynom 

/*
int main()
{

	system("PAUSE");
    return 0;
}
*/
#include "stdafx.h"
#include "field_element.h"

// Extended Euclidean algorithm
void extended_euclid(int a, int b, int *x, int *y, int *d)
{
	// calculates a * *x + b * *y = gcd(a, b) = *d

	int q, r, x1, x2, y1, y2;

	if (b == 0)
	{
		*d = a, *x = 1, *y = 0;
		return;
	}

	x2 = 1, x1 = 0, y2 = 0, y1 = 1;

	while (b > 0)
	{
		q = a / b, r = a - q * b;
		*x = x2 - q * x1, *y = y2 - q * y1;
		a = b, b = r;
		x2 = x1, x1 = *x, y2 = y1, y1 = *y;
	}

	*d = a, *x = x2, *y = y2;
}
field_element::field_element()	//Def 1 mod 2
{
	characteristic = 2;
	element = 1;
}
field_element::field_element(int _characteristic)
{
	characteristic = _characteristic;
	element = 0;
}
field_element::field_element(int _element, int _characteristic)
{
	element = _element;
	characteristic = _characteristic;
	element = element % characteristic;
	if (element < 0) element = element + characteristic;
}
field_element::~field_element()
{
}
int field_element::get_inverse(int _element)
{
	int gcd, x, y;
	set_element(_element);

	extended_euclid(get_element(), characteristic, &x, &y, &gcd);

	if (gcd == 1)
	{
		cout << "x = " << x;
		set_element(x);
		return get_element();
	}
		
	return 0;
}
field_element field_element::operator+(field_element right)
{
	return field_element(element + right.get_element(), characteristic);
}
field_element field_element::operator+(int right)
{
	return field_element(element + right, characteristic);
}
field_element field_element::operator*(field_element right)
{
	return field_element(element * right.get_element(), characteristic);
}
field_element field_element::operator*(int right)
{
	return field_element(element * right, characteristic);
}
ostream &operator<<(ostream &stream, field_element f)
{
	stream << f.get_element();

	return stream;
}
 field_element &operator+=(field_element &left, field_element &right)
{
    //left.set_element((left.get_element() + right.get_element()) % left.get_characteristic());
	left.element = (left.element + right.element) % left.characteristic;
	return left;
}
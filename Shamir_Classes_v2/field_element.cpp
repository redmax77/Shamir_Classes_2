#include "stdafx.h"
#include "field_element.h"

field_element::field_element()
{

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


/*
  TODO: check characteristics
 field_element operator+=(field_element &left, field_element right)
{
    left.set_element((left.get_element() + right.get_element()) % left.get_characteristic());

    return left;
}
 */
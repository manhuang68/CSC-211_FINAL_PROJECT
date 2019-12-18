#include "stdafx.h"
#include "Number.h"
Number::Number()
{
	this->case4 = 0;
	this->case5 = 0;
}
void Number::numero(int y)
{
	this->case5 = y;
};

/*float Number::getcase()
{
	return case4;
}
int Number::loco()
{
	case6 =case4 + 30.0;
	return case6;
}*/

int Number::getTime()
{
	return case5;
}
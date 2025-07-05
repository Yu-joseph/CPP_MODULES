#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& ls)
{
	(void)ls;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ls)
{
	if(this != &ls)
	{
	}
	return *this;
}



void ScalarConverter::convert(std::string& str)
{
	type finder = is_type(str);
	// std::cout << finder << std::endl;
	switch (finder)
	{
	case TYPE_CHAR:
		convert_char(str);
		break;
	case SPECIAL:
		convert_spcl(str);
		break;
	case TYPE_INT:
		convert_int(str);
		break;
	case TYPE_FLOAT:
		convert_float(str);
		break;
	case TYPE_DOUBLE:
		convert_double(str);
		break;
	default:
		std::cout << "invalid input" << std::endl;
		break;
	}
}


ScalarConverter::~ScalarConverter(){}
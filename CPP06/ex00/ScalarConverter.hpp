#pragma once

#include <iostream>
#include <string>
#include <iomanip>


enum type { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_UNKNOWN , SPECIAL};

// typedef	struct s_info
// {
// 	float fl;
// 	long i;
// 	double d;
// }t_info;



class ScalarConverter
{
private:
	
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& ls);
	ScalarConverter& operator=(const ScalarConverter& ls);
	~ScalarConverter();
	static void convert(std::string& str);
	//**/*/*/*/*/*/*/*/*/*/*/
};
type is_type(std::string &str);
void convert_char(std::string str);
void convert_spcl(std::string str);
void convert_int(std::string str);
void convert_float(std::string str);
void convert_double(std::string str);

// void check_type(std::string str);

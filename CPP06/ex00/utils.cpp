#include "ScalarConverter.hpp"
#include <cerrno>
#include <limits>
#include <cstdlib>


// #include <cctype>
// #include <string>
// type is_type(std::string &str)
// {
// 	char x = str[1];
// 	size_t l = str.size();
// 	if (l != 1 && isprint(x))
// 		return TYPE_CHAR;
// 	else if()
// }

// #include <iostream>

// enum Type { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_UNKNOWN };

type is_type(std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf" ||
        str == "-inf" || str == "+inf" || str == "nan")
        return SPECIAL;

    if (str.length() == 1 && !std::isdigit(str[0]))
        return TYPE_CHAR;

    char* end;
    if (str.find('.') == std::string::npos && str.find('f') == std::string::npos)
    {
        // std::cout << "LOS" << std::endl;
        errno = 0;
        std::strtol(str.c_str(), &end, 10);
        if (*end == '\0' && errno != ERANGE)
            return TYPE_INT;
    }
    errno = 0;
    std::strtof(str.c_str(), &end);
    if (str.find('.') != std::string::npos && *end == 'f' && *(end + 1) == '\0')
    {
        // std::cout << "jackkkk" << std::endl;
        return TYPE_FLOAT;
    }
    errno = 0;
    std::strtod(str.c_str(), &end);
    if (*end == '\0' && errno != ERANGE)
        return TYPE_DOUBLE;

    return TYPE_UNKNOWN;
}


void convert_char(std::string str)
{
    // std::cout << str << std::endl;
    // std::cout << str << std::endl;
    char c = str[0];
    // std::cout << c << std::endl;
    if (std::isprint(c))
    {
        std::cout << "char: '" << c << "'" << std::endl; 
    }else
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}


void convert_int(std::string str)
{
    // std::cout << str << std::endl;
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);
    if (val < 0 || val > 127)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else{
        if (std::isprint(val))
        {
            std::cout << "char : " <<"'"<< static_cast<char>(val) <<"'"<< std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    if (val < -std::numeric_limits<int>::max() || val > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(val) << 'f' << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(val) << std::endl;
}

void convert_spcl(std::string str)
{
    if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	if (str == "-inff" || str == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	if (str == "+inff" || str == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void convert_float(std::string str)
{
    char* end;
    errno = 0;
    float val = std::strtof(str.c_str(), &end);

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<unsigned char>(val)))
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (val < static_cast<double>(std::numeric_limits<int>::min()) ||
        val > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max() || errno == ERANGE)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(val) << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void convert_double(std::string str)
{
    char* end;
    errno = 0;
    double val = std::strtod(str.c_str(), &end);

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<unsigned char>(val)))
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (val < static_cast<double>(std::numeric_limits<int>::min()) ||
        val > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max() || errno == ERANGE)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(val) << "f" << std::endl;

    if (val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max() || errno == ERANGE)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double: " << val << std::endl;
}



// void convert_double(std::string str)
// {
//     char* end;
//     double val = std::strtod(str.c_str(), &end);
//     if (val < 0 || val > 127)
//     {
//         std::cout << "char: impossible" << std::endl;
//     }
//     else{
//         if (std::isprint(val))
//         {
//             std::cout << "char : " <<"'"<< static_cast<char>(val) <<"'"<< std::endl;
//         }
//         else
//             std::cout << "char: Non displayable" << std::endl;
//     }
//     if (val < -std::numeric_limits<int>::max() || val > std::numeric_limits<int>::max())
// 		std::cout << "int: impossible" << std::endl;
// 	else
// 		std::cout << "int: " << static_cast<int>(val) << std::endl;
//     if (val < std::numeric_limits<float>::min() || val > std::numeric_limits<float>::max())
// 		std::cout << "float: impossible" << std::endl;
// 	else
// 		std::cout << "float: " << static_cast<float>(val) << std::endl;
//     if (val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max())
// 		std::cout << "double: impossible" << std::endl;
// 	else
// 		std::cout << "double: " << static_cast<double>(val) << std::endl;
// }
// #include <iostream>
#include "Serializer.hpp"
// struct Data
// {
// private:
// 	std::string	s;
// 	char 		grade;
// 	int			age;
// public:
// 	Data(std::string _s, int _a, char _g) : s(_s), age(_a), grade(_g) {} 
// };


int	main()
{
	Data d;
	d.nb = 57;
	Data *s = &d;
	uintptr_t raw = Serializer::serialize(s);
	std::cout << reinterpret_cast<void*>(raw) << std::endl;
	std::cout << &d << std::endl;

	Data* result = Serializer::deserialize(raw);
	if(result == s)
		std::cout << "Deserialized......" << std::endl;
    std::cout << "Deserialized value: " << result->nb << std::endl;
	// std::string *s = reinterpret_cast<std::string*>(&d);
	// std::cout << *s << std::endl;
	// s++;
	// int *a = reinterpret_cast<int*>(s);
	// std::cout << *a << std::endl;

}
#pragma once 


#include <iostream>

struct Data
{
	int nb;
};

class Serializer
{
public:
	Serializer();
	Serializer& operator=(const Serializer& ls);
	Serializer(const Serializer& ls);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	~Serializer();
};

//https://youtube.com/shorts/WONZNlUB1_Y?si=7A8Bu8wwjNUn_psR
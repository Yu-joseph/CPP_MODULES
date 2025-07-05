#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& ls)
{
	(void)ls;
}
Serializer& Serializer::operator=(const Serializer& ls)
{
	if(this != &ls)
	{
	}
	return *this;
}


uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

Serializer::~Serializer(){};
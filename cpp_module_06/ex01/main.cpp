#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data originData;

	uintptr_t dataAddress1 = Serializer::serialize(&originData);
	Data *dataAddress2 = Serializer::deserialize(dataAddress1);

	if (&originData == dataAddress2)
		std::cout << "test success" << std::endl;
	else std::cout << "test fail" << std::endl;
	return 0;
}

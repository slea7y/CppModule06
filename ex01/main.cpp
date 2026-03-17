#include <iostream>
#include "Serializer.hpp"

int main() {
	
	Data ptr;
	Data *comparePtr;
	uintptr_t raw;
// std::cout << "Beginning computations..." << std::flush;

	ptr.age = 13;
	ptr.name = "slawyslaw";


	raw = Serializer::serialize(&ptr);
	comparePtr = Serializer::deserialize(raw);
// std::cout << "check computations..." << std::flush;

	std::cout << (&ptr == comparePtr) << std::endl;
} 
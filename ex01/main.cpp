#include <cstddef>
#include <iostream>
#include "Serializer.hpp"

int main() {
	
	Data ptr;
	Data *comparePtr;
	uintptr_t raw;

	ptr.age = 13;
	ptr.name = "slawyslaw";


	raw = Serializer::serialize(&ptr);

	//to test
	// comparePtr = nullptr;
	comparePtr = Serializer::deserialize(raw);
	std::string result = (&ptr == comparePtr) ? "true" : "false";
	std::cout << result << std::endl;
} 
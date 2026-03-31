#include <cstddef>
#include <iostream>
#include "Serializer.hpp"

#include <string>


//just a helper to visualise what we r doing here
std::string toHex(uintptr_t raw){
	std::string hex = "0123456789abcdef";
	std::string res;

	while (raw > 0) {
		res = hex[raw % 16] + res;
		raw /= 16;
	}
	return(res);
}

int main() {
	
	Data ptr;
	Data *comparePtr;
	uintptr_t raw;

	ptr.age = 13;
	ptr.name = "blab";
	raw = Serializer::serialize(&ptr);
	// std::cout << "ptr ad "<< &ptr << std::endl;
	// std::cout << "raw val 0x"<< toHex(raw) << std::endl;
	
	comparePtr = Serializer::deserialize(raw);
	std::string result = (&ptr == comparePtr) ? "true" : "false";
	std::cout << result << std::endl;

	// std::cout << "ptr values "<< ptr.age << " "<< ptr.name << std::endl;
	// std::cout << "comparePtr values "<< comparePtr->age << " "<< comparePtr->name << std::endl;

	// std::cout << "ptr adres "<< &ptr << std::endl;
	// std::cout << "comparePtr adres "<< comparePtr << std::endl;
} 
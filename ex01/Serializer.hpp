#include "iostream"
#include <string>

struct Data {
	std::string name;
	int age;
};

class Serializer {
	public:
		static uintptr_t serialize(Data *ptr);
		// It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static Data* deserialize(uintptr_t raw);
		// It takes an unsigned integer parameter and converts it to a pointer to Data
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer &operator=(const Serializer& other);
		~Serializer();
	};
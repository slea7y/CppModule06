#include "Serializer.hpp"

// reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. 
// The operation result is a simple binary copy of the value from one pointer to the other. All pointer 
// conversions are allowed: neither the content pointed nor the pointer type itself is checked.


Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

//uintptr_t unsigned integer type capable of holding a pointer to void
uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

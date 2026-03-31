#include "Base.hpp"
#include "ABC.hpp"
#include <exception>


int main(){
	srand(time(NULL));
	Base* bPtr;

	bPtr = Base::generate();

	Base::identify(bPtr);

	B b;

	Base::identify(b);

	delete bPtr;
}
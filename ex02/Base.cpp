#include "Base.hpp"
#include "ABC.hpp"
#include <cstdio>
#include <cstdlib>
#include <typeinfo>

Base::~Base() {
	std::cout << "Base destructor" << std::endl;
}

Base* Base::generate() {
	int random = rand() % 3;
	Base* bPtr;

	if (random == 0) {
		A *a = new A;
		bPtr = dynamic_cast<Base*>(a);
		return (bPtr);
	}
	else if (random == 1) {
		B *a = new B;
		bPtr = dynamic_cast<Base*>(a);
		return (bPtr);
	}
	else {
		C *a = new C;
		bPtr = dynamic_cast<Base*>(a);
		return (bPtr);
	} 
}

bool checkA(Base* p) {
	try {
		A& r1 = dynamic_cast<A&>(*p);
		(void)r1;
	}
	catch (std::exception& e) {
		return 0; 
	}
	return 1;
}

bool checkB(Base* p) {
	try {
		B& r1 = dynamic_cast<B&>(*p);
		(void)r1;
	}
	catch (std::exception& e) {
		return 0; 
	}
	return 1;
}

bool checkC(Base* p) {
	try {
		C& r1 = dynamic_cast<C&>(*p);
		(void)r1;
	}
	catch (std::exception& e) {
		return 0; 
	}
	return 1;
}

void Base::identify(Base* p) {
	std::string type;
	if (checkA(p))
		type = "A";
	if (checkB(p))
		type = "B";
	if (checkC(p))
		type = "C";
	std::cout << "Type: "<< type << "!" << std::endl;
}

bool checkARef(Base& p) {
	try {
		A& r1 = dynamic_cast<A&>(p);
		(void)r1;
	}
	catch (std::exception& e) {
		return 0; 
	}
	return 1;
}

bool checkBRef(Base& p) {
	try {
		B& r1 = dynamic_cast<B&>(p);
		(void)r1;
	}
	catch (std::exception& e) {
		return 0; 
	}
	return 1;
}

bool checkCRef(Base& p) {
	try {
		C& r1 = dynamic_cast<C&>(p);
		(void)r1;
	}
	catch (std::exception& e) {
		return 0; 
	}
	return 1;
}


void Base::identify(Base& p){
	// printf("called!\n");
	std::string type;
	if (checkARef(p))
		type = "A";
	if (checkBRef(p))
		type = "B";
	if (checkCRef(p))
		type = "C";
	std::cout << "Type: "<< type << "!" << std::endl;
}

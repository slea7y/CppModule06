#pragma once
#include "iostream"
#include <ostream>

class Base {
	public:
		virtual ~Base();

		static Base* generate();
		// 		It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
		// to use anything you like for the random choice implementation.
		static void identify(Base* p);
		// It prints the actual type of the object pointed to by p: "A", "B", or "C".
		static void identify(Base& p);
		// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
		// inside this function is forbidden
};

std::ostream &operator<<(std::ostream &os, const Base &obj);
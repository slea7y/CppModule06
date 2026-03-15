#include "ScalarConvert.hpp"
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <iosfwd>
#include <stdio.h>

ScalarConverte::ScalarConverte() {}

ScalarConverte::~ScalarConverte() {}

bool isInt(std::string& string) {
	try {
		size_t pos = 0;
		std::stoi(string, &pos);
		if (pos == string.length())
			return (true);
	}
	catch (std::exception &e) {
		return (false);
	}
	return (false);
}

bool isDouble(std::string& string) {
	try {
		size_t pos = 0;
		std::stod(string, &pos);
		if (pos == string.length())
			return (true);
		if (!string.compare("-inf") || !string.compare("+inf") || !string.compare("nan"))
			return (true);
	}
	catch (...) {
		return (false);
	}
	return (false);
}

bool isChar(std::string& string) {
	if (string.length() != 1)
		return (false);
	if (!isascii(string.at(0)) || std::isdigit(string.at(0))) 
		return (false);
	return (true);
}

bool isFloat(std::string& string) {
	try {
		size_t pos = 0;
		std::stof(string, &pos);
		if (pos == (string.length() - 1)
			&& string.at(string.length() - 1) == 'f')
			return (true);
		if (!string.compare("-inff") || !string.compare("+inff") || !string.compare("nanf"))
			return (true);
	}
	catch (std::exception &e){
		return (false);
	}
	return (false);
}


void handleInt(std::string& string) {
	int i = std::stoi(string);

	// i = 'a';
	// char c = static_cast<char>(i);

	float f = static_cast<float>(i) + 0.0f;
	std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << i << std::endl;
}

void handleFloat(std::string& string) {
	float f = std::stof(string);
	char c = (char)f;
	int i = (int)f;
	double d = (double)f;
	size_t precision = string.length() - string.find(".") - 2;

	if (f > 19 && f < 127)
		std::cout << "char: '" << c << "'"<< std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::setprecision(precision) << std::fixed << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverte::convert(std::string& string) {
	// int i = 0;
	if (isChar(string)) {
		std::cout << "yayy its char" << std::endl ;
	}
	else if (isInt(string)) {
		// i = 2;
		std::cout << "yayy its int" << std::endl ;
		handleInt(string);
	}
	else if (isFloat(string)) {
		// i = 3;
		std::cout << "yayy its float" << std::endl ;
		handleFloat(string);
	}
	else if (isDouble(string)) {
		// i = 4;
		string = std::stoi(string);
		std::cout << "yayy its double" << std::endl ;
	}


	// std::cout << "char: " << string << std::endl ;
	// std::cout << "int: " << string << std::endl ;
	// std::cout << "float: " << string << std::endl ;
	// std::cout << "double: " << string << std::endl ;
	// else ()
}
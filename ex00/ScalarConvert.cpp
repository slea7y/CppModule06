#include "ScalarConvert.hpp"
#include <climits>
#include <exception>
#include <iomanip>
#include <iosfwd>

ScalarConverte::ScalarConverte() {}

ScalarConverte::~ScalarConverte() {}

enum TYPE {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

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
		if (!string.compare("-inff") || !string.compare("+inff")
			|| !string.compare("nanf"))
			return (true);
	}
	catch (std::exception &e){
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
		if (!string.compare("-inf") || !string.compare("+inf")
			|| !string.compare("nan"))
			return (true);
	}
	catch (...) {
		return (false);
	}
	return (false);
}

void handleChar(std::string& string) {
	char c = static_cast<char>(string[0]);
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	
	std::cout << "char: '" << c << "'"<< std::endl;
	if (i > INT_MIN && i < INT_MAX)
		std::cout << "int: " << i << std::endl;
	else 
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::setprecision(1)
				<< std::fixed << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void handleInt(std::string& string) {
	int i = std::stoi(string);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	
	if (i > 32 && i < 127)
		std::cout << "char: '" << c << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MIN && i < INT_MAX)
		std::cout << "int: " << i << std::endl;
	else 
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::setprecision(1)
				<< std::fixed << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void handleFloat(std::string& string) {
	float f = std::stof(string);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	size_t precision = string.length() - string.find(".") - 2;

	if (f > 32 && f < 127)
		std::cout << "char: '" << c << "'"<< std::endl;
	else if (!string.compare("-inff") || !string.compare("+inff")
		|| !string.compare("nanf")) 
		std::cout << "char: " << "impossible" << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MIN && i < INT_MAX)
		std::cout << "int: " << i << std::endl;
	else 
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::setprecision(precision)
				<< std::fixed << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void handleDouble(std::string& string) {
	double d = std::stod(string);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	size_t precision = string.length() - string.find(".") - 1;

	if (d > 32 && d < 127)
		std::cout << "char: '" << c << "'"<< std::endl;
	else if (!string.compare("-inf") || !string.compare("+inf")
		|| !string.compare("nan")) 
		std::cout << "char: " << "impossible" << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MIN && i < INT_MAX)
		std::cout << "int: " << i << std::endl;
	else 
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::setprecision(precision)
				<< std::fixed << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void detectType(TYPE *type, std::string& string) {
	if (isChar(string))
		*type = CHAR;
	else if (isInt(string))
		*type = INT;
	else if (isFloat(string))
		*type = FLOAT;
	else if (isDouble(string))
		*type = DOUBLE;
	else
		*type = INVALID;
}

void ScalarConverte::convert(std::string& string) {
	TYPE type;
	
	detectType(&type, string);
	switch (type) {
		case CHAR:
			return handleChar(string);
		case INT:
			return handleInt(string);
		case FLOAT:
			return handleFloat(string);
		case DOUBLE:
			return handleDouble(string);
		case INVALID:
			std::cout << "Invalid input 😔😔😔!" << std::endl ;
	}
	
}

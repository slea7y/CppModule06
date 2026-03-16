#include "ScalarConvert.hpp"
#include <cctype>
#include <climits>
#include <exception>
#include <iomanip>
#include <iosfwd>

bool isInt(const std::string& string) {
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

bool isChar(const std::string& string) {
	if (string.length() != 1)
		return (false);
	if (!isascii(string.at(0)) || std::isdigit(string.at(0))) 
		return (false);
	return (true);
}

bool isFloat(const std::string& string) {
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

bool isDouble(const std::string& string) {
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

void ScalarConverte::handleChar(const std::string& string) {
	char c = static_cast<char>(string[0]);
	
	std::cout << "char: '" << c << "'"<< std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::setprecision(1)
				<< std::fixed << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverte::handleInt(const std::string& string) {
	int i = std::stoi(string);
	
	if (std::isprint(static_cast<char>(i)))
		std::cout << "char: '" << static_cast<char>(i) << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MIN && i < INT_MAX)
		std::cout << "int: " << i << std::endl;
	else 
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::setprecision(1)
				<< std::fixed << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverte::handleFloat(const std::string& string) {
	float f = std::stof(string);
	size_t precision = 0;

	string.find(".", precision);
	if (precision > 0)
	
		precision = string.length() - string.find(".") - 1;
	else
		precision = 1;

	if (std::isprint(static_cast<char>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'"<< std::endl;
	else if (!string.compare("-inff") || !string.compare("+inff")
		|| !string.compare("nanf")) 
		std::cout << "char: " << "impossible" << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	if (static_cast<int>(f) > INT_MIN && static_cast<int>(f) < INT_MAX)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else 
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::setprecision(precision)
				<< std::fixed << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverte::handleDouble(const std::string& string) {
	double d = std::stod(string);
	size_t precision = 0;

	string.find(".", precision);
	if (precision > 0)
	
		precision = string.length() - string.find(".") - 1;
	else
		precision = 1;

	if (std::isprint(static_cast<char>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'"<< std::endl;
	else if (!string.compare("-inf") || !string.compare("+inf")
		|| !string.compare("nan")) 
		std::cout << "char: " << "impossible" << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
	if (d > INT_MIN && d < INT_MAX)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else 
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::setprecision(precision)
				<< std::fixed << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverte::detectType(TYPE *type, const std::string& string) {
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

void ScalarConverte::convert(const std::string& string) {
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
			std::cout << "Invalid input 😔😔😔!" << std::endl;
			return ;
	}
}

#include "ScalarConvert.hpp"

int main(int ac, char **av) {
	if (ac != 2)
		return (0);
	std::string string(av[1]);
	ScalarConverte::convert(string);
}

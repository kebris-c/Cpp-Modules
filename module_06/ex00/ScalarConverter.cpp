#include "ScalarConverter.hpp"

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cctype>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isPseudoLiteral(const std::string &s)
{
	return (s == "nan" || s == "+inf" || s == "-inf" || s == "nanf" ||
			s == "+inff" || s == "-inff");
}

bool ScalarConverter::isCharLiteral(const std::string &s)
{
	return s.size() == 3 && s[0] == '\'' && s[2] == '\'';
}

void ScalarConverter::printFromDouble(double d)
{
	// char
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	// int
	if (std::isnan(d) || std::isinf(d) || d < static_cast<double>(INT_MIN) ||
		d > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	// float
	float f = static_cast<float>(d);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
			  << std::endl;

	// double
	std::cout << "double: " << std::fixed << std::setprecision(1) << d
			  << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (isCharLiteral(literal))
	{
		char c = literal[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)
				  << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1)
				  << static_cast<double>(c) << std::endl;
		return;
	}
	if (literal.size() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)
				  << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1)
				  << static_cast<double>(c) << std::endl;
		return;
	}

	bool hasF = literal.size() > 1 && literal[literal.size() - 1] == 'f' &&
				!isPseudoLiteral(literal);
	std::string toParse = hasF ? literal.substr(0, literal.size() - 1) : literal;

	char *end = 0;
	errno = 0;
	double d = std::strtod(toParse.c_str(), &end);

	if (end == toParse.c_str() || *end != '\0' ||
		(errno == ERANGE && !isPseudoLiteral(literal)))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printFromDouble(d);
}

#include "ScalarConverter.hpp"

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
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
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (std::isnan(d) || std::isinf(d) || d < static_cast<double>(INT_MIN) ||
		d > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	float f = static_cast<float>(d);
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-" : "+") << "inff" << std::endl;
	else
	{
		std::cout << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-" : "+") << "inf" << std::endl;
	else
	{
		std::cout << d;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << std::endl;
	}
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
		std::cout << "float: " << static_cast<float>(c);
		if (static_cast<float>(c) == static_cast<int>(static_cast<float>(c)))
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c);
		if (static_cast<double>(c) == static_cast<int>(static_cast<double>(c)))
			std::cout << ".0";
		std::cout << std::endl;
		return;
	}
	if (literal.size() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c);
		if (static_cast<float>(c) == static_cast<int>(static_cast<float>(c)))
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c);
		if (static_cast<double>(c) == static_cast<int>(static_cast<double>(c)))
			std::cout << ".0";
		std::cout << std::endl;
		return;
	}

	// strtod entiende nan / +inf / -inf. El sufijo f de float (42.0f, nanf, +inff)
	// hay que quitarlo. Ojo: "+inf" y "-inf" también terminan en 'f' (la de "inf");
	// no se les quita esa letra.
	std::string toParse = literal;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		toParse = literal.substr(0, literal.size() - 1);
	else if (literal.size() > 1 && literal[literal.size() - 1] == 'f' &&
			 literal != "+inf" && literal != "-inf")
		toParse = literal.substr(0, literal.size() - 1);

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

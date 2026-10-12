#include "ScalarConverter.hpp"

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

static void writeScaled(float value)
{
	std::ostringstream out;
	out << value;
	std::string text = out.str();
	if (text.find('.') == std::string::npos && text.find('e') == std::string::npos &&
		text.find('E') == std::string::npos)
		text += ".0";
	std::cout << text << "f" << std::endl;
}

static void writeScaled(double value)
{
	std::ostringstream out;
	out << value;
	std::string text = out.str();
	if (text.find('.') == std::string::npos && text.find('e') == std::string::npos &&
		text.find('E') == std::string::npos)
		text += ".0";
	std::cout << text << std::endl;
}

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

	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-" : "+") << "inff" << std::endl;
	else
	{
		float f = static_cast<float>(d);
		if (std::isinf(f))
			std::cout << "impossible" << std::endl;
		else
			writeScaled(f);
	}

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-" : "+") << "inf" << std::endl;
	else
		writeScaled(d);
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
		std::cout << "float: ";
		writeScaled(static_cast<float>(c));
		std::cout << "double: ";
		writeScaled(static_cast<double>(c));
		return;
	}
	if (literal.size() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: ";
		writeScaled(static_cast<float>(c));
		std::cout << "double: ";
		writeScaled(static_cast<double>(c));
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

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	static bool isPseudoLiteral(const std::string &s);
	static bool isCharLiteral(const std::string &s);
	static void printFromDouble(double d);

  public:
	static void convert(const std::string &literal);
};

#endif

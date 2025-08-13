#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter&	operator=(const ScalarConverter&);
		~ScalarConverter();

	public:
		static void	convert(const std::string& literal);

};

void	displayConversionResult(const std::string& rChar, const std::string& rInt,
								const std::string& rFloat, const std::string& rDouble);
std::string	checkIntBounds(long long rInt);
std::string	checkCharBounds(long long rChar);
std::string	checkFloatBounds(const std::string& literal, char* endptr);
std::string	checkDoubleBounds(const std::string& literal, char* endptr);

#endif

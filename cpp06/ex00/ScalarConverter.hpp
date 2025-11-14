#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		
		ScalarConverter& operator=(const ScalarConverter& other);

		~ScalarConverter();

	public:
		// int keyDedect(std::string input, char key);
		// if dedected return 1 if not retrun 0
		// int getType(std::string input); 
		// char   = 1
		// int    = 2
		// float  = 3
		// double = 4


		// char convertChar(std::string input);
		// int convertInt(std::string input);
		// float convertFloat(std::string input);
		// double convertDouble(std::string input);

		// void printConversations(const std::string input);

		static void convert(const std::string input);
};

#endif

#include "Span.hpp"

int main() {
	{
		std::cout << "----- Test 1 -----" << std::endl << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl << "----- Finish -----" << std::endl;
	}
	{
		std::cout << "----- Test 2 -----" << std::endl << std::endl;
		Span sp = Span(10000);

		for (int i = 0; i < 10000; i++)
			sp.addNumber(i);

		// std::cout << sp << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl << "----- Finish -----" << std::endl;
	}
	{
		std::cout << "----- Test 3 -----" << std::endl << std::endl;
		Span sp = Span(1);

		try {
			sp.addNumber(1);
			sp.addNumber(2);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		std::cout << std::endl << "----- Finish -----" << std::endl;
	}
	{
		std::cout << "----- Test 4 -----" << std::endl << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < 30000; i += 2) {
			vec.push_back(i);
		}

		Span sp = Span(15000);
		Span sptest = Span(14999);

		try {
			sp.addNumbers(vec);
			sptest.addNumbers(vec);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			sp.addNumbers(vec.begin(), vec.end());
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		std::cout << std::endl << "----- Finish -----" << std::endl;
	}
}
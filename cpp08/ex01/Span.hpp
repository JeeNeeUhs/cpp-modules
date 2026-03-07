#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class	Span {
	private:
		std::vector<int>	numbers;
		unsigned int		len;
		unsigned int		count;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);

		Span&	operator=(const Span& other);
		
		~Span();

		int		getMaxSize() const;
		int		getCurrentSize() const;

		void	addNumber(int num);
		void	addNumbers(std::vector<int> nums);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int		shortestSpan() const;
		int		longestSpan() const;

		int		operator[](unsigned int index) const;
		int&	operator[](unsigned int index);

		class	FullSpan : public std::exception {
			public:
				const char* what() const throw() {
					return ("Span is full. Cannot add more numbers.");
				}
			};

		class	ListTooLarge : public std::exception {
			public:
				const char* what() const throw() {
					return ("The list of numbers is too large to fit this span.");
				}
			};

		class	NotEnoughSpan : public std::exception {
			public:
				const char* what() const throw() {
					return ("Not enough numbers to find a span.");
				}
			};

		class	IndexOutOfBounds : public std::exception {
			public:
				const char* what() const throw() {
					return ("Index out of bounds.");
				}
			};
};

std::ostream& operator<<(std::ostream& os, const Span& span);

#endif

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int first);
		Fixed(const float first);
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator=(const Fixed &other);
		int getRawBits() const;
		void setRawBits(int raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
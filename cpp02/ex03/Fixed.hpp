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

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);

		Fixed &operator++(); // pre-increment
		Fixed operator++(int); // post-increment
		Fixed &operator--(); // pre-decrement
		Fixed operator--(int); // post-decrement

		Fixed &operator=(const Fixed &other);

		int getRawBits() const;
		void setRawBits(int raw);
		float toFloat() const;
		int toInt() const;

		static int min(Fixed &a, Fixed &b);
		static int min(const Fixed &a, const Fixed &b);
		static int max(Fixed &a, Fixed &b);
		static int max(const Fixed &a, const Fixed &b);
};


std::ostream &operator<<(std::ostream &os, const Fixed &fixed);





#endif
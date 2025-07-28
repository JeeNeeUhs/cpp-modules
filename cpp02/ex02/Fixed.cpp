#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int first) : value(first << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float first) : value(roundf(first * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->value++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->value--;
	return temp;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->value = other.value;
	}
	return *this;
}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(int raw) {
	this->value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->value) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return this->value >> fractionalBits;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}


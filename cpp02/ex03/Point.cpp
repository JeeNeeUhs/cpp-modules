#include <iostream>
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) {
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {
	std::cout << "Point destructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}

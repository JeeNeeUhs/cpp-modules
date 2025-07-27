#include <iostream>
#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 15);
	
	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "A(0, 0), B(20, 0), C(10, 15)" << std::endl;
	std::cout << std::endl;
	
	Point inside(10, 5);
	std::cout << "Test 1 - Point(10, 5):" << std::endl;
	if (bsp(a, b, c, inside)) {
		std::cout << "Point is inside the triangle" << std::endl;
	} else {
		std::cout << "Point is outside the triangle" << std::endl;
	}
	
	std::cout << std::endl;
	
	Point outside(25, 10);
	std::cout << "Test 2 - Point(25, 10):" << std::endl;
	if (bsp(a, b, c, outside)) {
		std::cout << "Point is inside the triangle" << std::endl;
	} else {
		std::cout << "Point is outside the triangle" << std::endl;
	}
	
	return 0;
}
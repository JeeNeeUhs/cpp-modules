#include "easyfind.hpp"
#include "easyfind.tpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
	{
		std::vector<int> v;
		for (int i = 10; i < 100; i += 10)
			v.push_back(i);
		try {
			std::vector<int>::iterator it = easyfind(v, 30);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::vector<int>::iterator it = easyfind(v, 35);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::list<int> l;
		for (int i = 20; i <= 100; i += 20)
			l.push_back(i);
		try {
			std::list<int>::iterator it = easyfind(l, 40);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::list<int>::iterator it = easyfind(l, 50);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::deque<int> d;
		for (int i = 1; i < 10; i += 1)
			d.push_back(i * i);
		try {
			std::deque<int>::iterator it = easyfind(d, 9);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::deque<int>::iterator it = easyfind(d, 42);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}

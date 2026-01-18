#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : arr(new T[0]), s(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), s(n) {}

template <typename T>
Array<T>::Array(const Array &other) : arr(new T[other.s]), s(other.s) {
	for (unsigned int i = 0; i < s; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array() {
	delete[] arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		delete[] arr;
		s = other.s;
		arr = new T[s];
		for (unsigned int i = 0; i < s; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= s)
		throw std::out_of_range("Index out of range");
	return arr[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const {
	if (i >= s)
		throw std::out_of_range("Index out of range");
	return arr[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return s;
}
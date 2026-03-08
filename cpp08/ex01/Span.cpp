#include "Span.hpp"
#include <limits>

Span::Span() : len(0), count(0) {}

Span::Span(unsigned int n) : len(n), count(0) {}

Span::Span(const Span& other) : numbers(other.numbers), len(other.len), count(other.count) {}

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		numbers = other.numbers;
		len = other.len;
		count = other.count;
	}
	return (*this);
}

Span::~Span() {}

int		Span::getMaxSize() const {
	return (len);
}

int		Span::getCurrentSize() const {
	return (count);
}

void	Span::addNumber(int num) {
	if (count >= len)
		throw FullSpan();

	numbers.push_back(num);
	count++;
}

void	Span::addNumbers(std::vector<int> nums) {
	if (count + nums.size() > len)
		throw ListTooLarge();

	numbers.insert(numbers.end(), nums.begin(), nums.end());
	count += nums.size();
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (count + std::distance(begin, end) > len)
		throw ListTooLarge();

	numbers.insert(numbers.end(), begin, end);
	count += std::distance(begin, end);
}

int		Span::shortestSpan() const {
	if (count < 2)
		throw NotEnoughSpan();

	int minSpan;
	int span;
	unsigned int i;
	unsigned int j;
	std::vector<int> sorted(numbers);

	std::sort(sorted.begin(), sorted.end());
	minSpan = std::numeric_limits<int>::max();
	j = sorted.size();

	for (i = 1; i < j; i++) {
		span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}

	return (minSpan);
}

int		Span::longestSpan() const {
	if (count < 2)
		throw NotEnoughSpan();

	return (*std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end()));
}

int		Span::operator[](unsigned int index) const {
	if (index >= count)
		throw IndexOutOfBounds();

	return (numbers[index]);
}

int&	Span::operator[](unsigned int index) {
	if (index >= count)
		throw IndexOutOfBounds();

	return (numbers[index]);
}

std::ostream& operator<<(std::ostream& os, const Span& span) {
	unsigned int i;

	i = span.getCurrentSize();
	os << "Span: [";
	for (unsigned int j = 0; j < i; j++) {
		os << span[j];
		if (j < i - 1)
			os << ", ";
	}
	os << "]";
	return (os);
}

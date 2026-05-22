#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : v(other.v), d(other.d) {}

PmergeMe::PmergeMe(int* arr, size_t size) {
	fill(arr, size);
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		v = other.v;
		d = other.d;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

template <typename T>
static bool isContainerSorted(const T& container) {
	if (container.size() <= 1) {
		return true;
	}
	
	typename T::const_iterator it = container.begin();
	typename T::const_iterator next_it = it;
	++next_it;

	while (next_it != container.end()) {
		if (*next_it < *it) {
			return false;
		}
		++it;
		++next_it;
	}
	return true;
}

static size_t calcjacob(size_t n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return calcjacob(n - 1) + 2 * calcjacob(n - 2);
}

void PmergeMe::sortvector(std::vector<int>& vec) {
	if (vec.size() <= 1) {
		return;
	}

	std::vector<int> big;
	std::vector<int> small;
	bool odd = (vec.size() % 2 != 0);
	int left = 0;

	if (odd) {
		left = vec.back();
		vec.pop_back();
	}

	for (size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i] < vec[i + 1]) {
			small.push_back(vec[i]);
			big.push_back(vec[i + 1]);
		} else {
			small.push_back(vec[i + 1]);
			big.push_back(vec[i]);
		}
	}

	sortvector(big);
	// after this function call, big is sorted

	if (!small.empty()) {
		std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[0]);
		big.insert(it, small[0]);
	}

	size_t pendsize = small.size();
	size_t jindex = 3;
	size_t inserted = 1;
	size_t prevjacob = 1;

	while (inserted < pendsize) {
		size_t curjacob = calcjacob(jindex);
		size_t index = (curjacob < pendsize) ? curjacob : pendsize;

		while (index > prevjacob) {
			size_t pendindex = index - 1;
			std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[pendindex]);
			big.insert(it, small[pendindex]);
			inserted++;
			index--;
		}
		prevjacob = curjacob;
		jindex++;
	}

	if (odd) {
		std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), left);
		big.insert(it, left);
	}
	
	vec = big;
}


void PmergeMe::sortdeque(std::deque<int>& deq) {
	if (deq.size() <= 1) {
		return;
	}

	std::deque<int> big;
	std::deque<int> small;
	bool odd = (deq.size() % 2 != 0);
	int left = 0;

	if (odd) {
		left = deq.back();
		deq.pop_back();
	}

	for (size_t i = 0; i < deq.size(); i += 2) {
		if (deq[i] < deq[i + 1]) {
			small.push_back(deq[i]);
			big.push_back(deq[i + 1]);
		} else {
			small.push_back(deq[i + 1]);
			big.push_back(deq[i]);
		}
	}

	sortdeque(big);

	if (!small.empty()) {
		std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[0]);
		big.insert(it, small[0]);
	}

	size_t pendsize = small.size();
	size_t jindex = 3;
	size_t inserted = 1;
	size_t prevjacob = 1;

	while (inserted < pendsize) {
		size_t curjacob = calcjacob(jindex);
		size_t index = (curjacob < pendsize) ? curjacob : pendsize;

		while (index > prevjacob) {
			size_t pendindex = index - 1;
			std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[pendindex]);
			big.insert(it, small[pendindex]);
			inserted++;
			index--;
		}
		prevjacob = curjacob;
		jindex++;
	}

	if (odd) {
		std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), left);
		big.insert(it, left);
	}

	deq = big;
}

void PmergeMe::print() {
	std::cout << "Before: ";
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	clock_t start = clock();
	sortvector(v);
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	start = clock();
	sortdeque(d);
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
	if (isContainerSorted(v) && isContainerSorted(d)) {
		std::cout << "Both containers are sorted correctly." << std::endl;
	} else {
		std::cout << "Error: One or both containers are not sorted correctly." << std::endl;
	}
}

void PmergeMe::fill(int* arr, size_t size) {
	v.assign(arr, arr + size);
	d.assign(arr, arr + size);
}
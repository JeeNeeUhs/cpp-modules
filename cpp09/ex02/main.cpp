#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int* arr = new int[argc - 1];
	for (int i = 1; i < argc; ++i) {
		arr[i - 1] = std::atoi(argv[i]);
		if (arr[i - 1] < 0) {
			std::cerr << "Error: All inputs must be positive integers." << std::endl;
			delete[] arr;
			return 1;
		}
	}

	PmergeMe sort;
	sort.fill(arr, argc - 1);
	sort.print();
	delete[] arr;
}
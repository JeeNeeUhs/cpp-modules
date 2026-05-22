#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

class PmergeMe {
	private:
		std::vector<int> v;
		std::deque<int> d;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe(int* arr, size_t size);

		PmergeMe& operator=(const PmergeMe& other);

		~PmergeMe();

		void sortvector(std::vector<int>& vec);
		void sortdeque(std::deque<int>& deq);
		void print();
		void fill(int* arr, size_t size); 
};

#endif

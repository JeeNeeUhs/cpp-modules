#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>

int main() {
	{
		std::cout << "----- Test 1 -----" << std::endl << std::endl;
		MutantStack<int> mstack;
		
		for (int i = 0; i < 300; i += 15) {
			mstack.push(i);
			if (i % 30 == 0) {
				mstack.pop();
			}
		}

		std::cout << mstack;

		MutantStack<int>::iterator it = mstack.begin();

		for (; it != mstack.end(); ++it) {
			(*it)++;
		}

		std::cout << mstack;

		std::stack<int> s(mstack);

		std::cout << s.top() << std::endl;

		std::cout << std::endl << "----- Finish -----" << std::endl;
	}
	{
		std::cout << "----- Test 2 -----" << std::endl << std::endl;
		std::list<int> mstack;
		
		for (int i = 0; i < 300; i += 15) {
			mstack.push_back(i);
			if (i % 30 == 0) {
				mstack.pop_back();
			}
		};

		std::cout << "List (front to back): " << std::endl;
		for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << std::endl;
		}

		std::list<int>::iterator it = mstack.begin();

		for (; it != mstack.end(); ++it) {
			(*it)++;
		}

		std::cout << "List (front to back): " << std::endl;
		for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << std::endl;
		}

		std::cout << std::endl << "----- Finish -----" << std::endl;

	}
}
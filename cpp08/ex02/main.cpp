#include "MutantStack.hpp"
#include "MutantStack.tpp"

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

		MutantStack<int>::iterator it = mstack.begin();

		for (; it != mstack.end(); ++it) {
			(*it)++;
		}

		std::cout << mstack;

		std::cout << std::endl << "----- Finish -----" << std::endl;
	}
	{

	}
	{

	}
}
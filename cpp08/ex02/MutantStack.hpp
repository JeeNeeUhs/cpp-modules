#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	private:

	public:
		MutantStack();
		MutantStack(const MutantStack& other);

		MutantStack& operator=(const MutantStack& other);

		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& mutantStack);

#endif
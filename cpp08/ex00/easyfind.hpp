#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int value);

class NotFound : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Value not found";
	}
};

#endif

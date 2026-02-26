#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &c, int val) {
	for (typename T::iterator it = c.begin(); it != c.end(); it++) {
		if (*it == val)
			return it;
	}
	throw NotFound();
}

#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &c, int val) {
	T::iterator it = std::find(c.begin(), c.end(), val);
	if (it != c.end())
		return (it);
	throw NotFound();
}

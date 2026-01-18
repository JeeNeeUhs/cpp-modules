#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T				*arr;
		unsigned int	s;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);

		~Array();

		Array<T> &operator=(const Array<T> &other);

		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;
		unsigned int	size() const;

};

#endif

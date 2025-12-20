#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

struct data {
	int		number;
	char	character;
	float	numberwithdot;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
		
		Serializer& operator=(const Serializer& other);

		~Serializer();

	public:
		static uintptr_t serialize(void* ptr);
		static data* deserialize(uintptr_t raw);
};

#endif

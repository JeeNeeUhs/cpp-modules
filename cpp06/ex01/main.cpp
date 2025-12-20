#include "Serializer.hpp"
#include <iostream>

int main() {
	data originalData;
	originalData.number = 42;
	originalData.character = 'A';
	originalData.numberwithdot = 3.14f;

	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized: " << std::endl;
	std::cout << "Raw value: " << raw << std::endl;

	data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized" << std::endl;
	std::cout << "Number: " << deserializedData->number << std::endl;
	std::cout << "Character: " << deserializedData->character << std::endl;
	std::cout << "Number with dot: " << deserializedData->numberwithdot << std::endl;

	return 0;
}

#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data data;
	data.id = 42;
	data.name = "serialization-test";
	data.score = 3.14;

	Data *original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data *restored = Serializer::deserialize(raw);

	std::cout << "original ptr : " << original << std::endl;
	std::cout << "serialized   : " << raw << std::endl;
	std::cout << "restored ptr : " << restored << std::endl;
	std::cout << "same pointer : " << (original == restored ? "yes" : "no")
			  << std::endl;
	std::cout << "restored data: id=" << restored->id << ", name=" << restored->name
			  << ", score=" << restored->score << std::endl;
	return 0;
}

#include <Duck.h>
#include <Functionality.h>
#include <Goose.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char** argv) {
	using namespace mlubecki;

	//6. Create a collection of Animals and fill it with 13 Ducks.
	const std::size_t NUMBER_OF_DUCKS = 13;

	AnimalCollectionT collection;
	collection.reserve(NUMBER_OF_DUCKS);
	for(auto i = 0; i < NUMBER_OF_DUCKS; ++i){
		collection.emplace_back(std::make_unique<Duck>());
	}

	//7. Create a function to find and remove the oldest Duck in the collection. Call it 21 times.
	const std::uint8_t NUMBER_OF_REMOVES = 21;
	for(auto i = 0; i < NUMBER_OF_REMOVES; ++i){
		removeOldestDuck(collection);
	}
	
	//11. Create a collection of 10 Ducks and 10 Geese.
	AnimalCollectionT geese_and_ducks;
	const std::size_t NUMBER_OF_GEESE_AND_DUCKS = 10;
	geese_and_ducks.reserve(2 * NUMBER_OF_GEESE_AND_DUCKS);
	for(auto i = 0; i < NUMBER_OF_GEESE_AND_DUCKS; ++i){
		geese_and_ducks.emplace_back(std::make_unique<Duck>());
		geese_and_ducks.emplace_back(std::make_unique<Goose>());
	}

	//12. Let's get loud. Call speak on all animals in your collection.
	for(const auto& animal : geese_and_ducks){
		animal->Speak();
	}

	//13.	Sort the Animal collection in descending order based on their age.
	std::sort(geese_and_ducks.begin(), geese_and_ducks.end(), compareDescending);

	//14.  Use a function to double check that the collection is sorted.
	bool double_check = std::is_sorted(geese_and_ducks.cbegin(), geese_and_ducks.cend(), compareDescending);
	std::cout << "Double check, is sorted? " << std::boolalpha << double_check << std::endl;

	//15. Calculate the total age of all the animals in your collection and use cout to output the value.
	std::cout << "Total age of animals: " << sumAges(geese_and_ducks) << std::endl;

	//16. Print out all the animals names in your collection to a file.
	saveNamesToFile(geese_and_ducks);

	return 0;
}

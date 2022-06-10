#pragma once

#include <Constants.h>

#include <cstdint>
#include <vector>
#include <memory>

namespace mlubecki{

    class Animal;

    using StoredT = std::unique_ptr<Animal>;
	using AnimalCollectionT = std::vector<StoredT>;

    std::uint8_t getRandomAge(std::uint8_t max_age = MAX_DUCK_AGE);

    void saveNamesToFile(const AnimalCollectionT& collection, const std::string& filename = "names.txt");

}
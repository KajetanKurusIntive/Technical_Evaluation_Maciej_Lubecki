#pragma once

#include <Utils.h>

namespace mlubecki{

    bool compareDescending(const StoredT& lhs, const StoredT& rhs);

	std::string determineDuckName(std::uint8_t age);
    
    std::string determineGooseName(std::uint8_t age);

	StoredT removeOldestDuck(AnimalCollectionT& collection);

    std::size_t sumAges(const AnimalCollectionT& collection);

}
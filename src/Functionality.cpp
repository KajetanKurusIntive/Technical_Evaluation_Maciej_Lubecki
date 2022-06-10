#include <Functionality.h>
#include <Duck.h>
#include <Constants.h>

#include <algorithm>
#include <fstream>
#include <random>

namespace mlubecki{

    //5. If the Duck's age is even, the name is "Lady Luck". Otherwise, their name is "Earl".
    std::string determineDuckName(std::uint8_t age){
        return age % 2 == 0 ? animal_names::DUCK_EVEN : animal_names::DUCK_ODD;
    }

    //10. If the Gooses age is even, the name is "Mother Goose". Otherwise, their name is "Bertram".
    std::string determineGooseName(std::uint8_t age){
        return age % 2 == 0 ? animal_names::GOOSE_EVEN : animal_names::GOOSE_ODD;
    }

    bool compareDescending(const StoredT& lhs, const StoredT& rhs){
        return lhs->GetAge() > rhs->GetAge();
    }

    bool compareAscending(const StoredT& lhs, const StoredT& rhs){
        return !compareDescending(lhs, rhs);
    }

    std::unique_ptr<Animal> removeOldestDuck(std::vector<std::unique_ptr<Animal>>& collection){
        if(collection.empty()){
            return nullptr;
        }
        
        auto oldest_animal_it = std::max_element(collection.begin(), collection.end(), compareAscending);
        auto result = std::move(*oldest_animal_it);
        std::swap(*oldest_animal_it, collection.back());
        collection.pop_back();

        return result;
    }

    std::size_t sumAges(const AnimalCollectionT& collection){
        auto op = [](std::size_t sum_so_far, const StoredT& rhs){
            return sum_so_far + rhs->GetAge();
        };
        return std::accumulate(collection.cbegin(), collection.cend(), 0ul, op);
    }

}
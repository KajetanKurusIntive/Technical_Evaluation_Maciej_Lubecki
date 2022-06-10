#include <Utils.h>
#include <Duck.h>
#include <Constants.h>

#include <fstream>
#include <iostream>
#include <random>

namespace mlubecki{

    namespace{

        class RNG{             
            std::mt19937 m_rng;
            std::uniform_int_distribution<std::uint8_t> m_uid;

        public:
            RNG(std::uint8_t max_number) 
                : m_rng(std::random_device()())
                , m_uid(0, max_number) 
            {}

            std::uint8_t get(){
                return m_uid(m_rng);
            }
        };

    }

    std::uint8_t getRandomAge(std::uint8_t max_age){
        static RNG rng(max_age);
        return rng.get();
    }

    void saveNamesToFile(const AnimalCollectionT& collection, const std::string& filename){
        std::ofstream output_file(filename);
        if(!output_file.is_open()){
            std::cerr << "Unable to open file " << filename << std::endl;
            return;
        }
        
        for(const auto& animal : collection){
            output_file << animal->GetName() << std::endl;
        }
        output_file.close();
    }
}
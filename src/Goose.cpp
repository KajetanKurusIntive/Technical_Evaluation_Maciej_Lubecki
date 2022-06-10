#include <Goose.h>
#include <Functionality.h>

#include <iostream>
#include <iomanip>

namespace mlubecki{

    Goose::Goose(std::uint8_t age) 
        : Animal(age, determineGooseName(age)) 
    {}

    //9. Geese get angrier the older they get. The angrier a goose gets, the longer they honk. Add an extra 'O' for each year of the goose's age.    
    void Goose::Speak() const {
        //the m_age + 2 is for the remaining "NK" letters
        std::cout << "HO" << std::setfill('O') << std::setw(m_age + 2) << "NK" << std::endl;
    }

}
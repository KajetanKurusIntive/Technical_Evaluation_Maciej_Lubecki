#include <Duck.h>
#include <Functionality.h>

#include <iostream>
#include <random>

namespace mlubecki{

    Duck::Duck(std::uint8_t age) 
        : Animal(age, determineDuckName(age)) 
    {}

    void Duck::Speak() const {
        std::cout << "Quack" << std::endl;
    }
}